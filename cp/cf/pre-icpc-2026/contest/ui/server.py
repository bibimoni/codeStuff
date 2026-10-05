#!/usr/bin/env python3
"""Live contest dashboard for the local AI-model programming contest.

Stdlib only. Serves GET / (HTML shell) and GET /api/state (JSON).
Data is re-read from disk on every /api/state request.

Run: python3 server.py --port 8777
"""
import argparse
import json
import os
import time
import re, subprocess
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))  # contest/
RESULTS = os.path.join(ROOT, "results")
TEAMS = os.path.join(ROOT, "teams")
MAP_TXT = os.path.join(ROOT, "map.txt")
META_JSON = os.path.join(ROOT, "meta.json")

DEFAULT_TEAMS = ["kimi-k3", "glm-5.3", "gpt-5.4-mini", "gpt-5.5-medium", "gpt-5.6-sol"]
VERDICTS = ("OK", "WA", "TL", "ML", "RE", "CE", "JE")
PENALTY_PER_FAIL = 20  # minutes
MAX_WS_FILE = 5 * 1024 * 1024


def load_map():
    """map.txt -> ordered list of {letter, slug}."""
    probs = []
    try:
        with open(MAP_TXT) as f:
            for line in f:
                parts = line.split()
                if len(parts) >= 3:
                    probs.append({"letter": parts[0], "slug": parts[2]})
    except OSError:
        pass
    return probs


def load_meta(now):
    try:
        with open(META_JSON) as f:
            m = json.load(f)
        if isinstance(m, dict) and "start_ts" in m:
            return m
    except (OSError, ValueError):
        pass
    return None


def load_rulings():
    try:
        with open(os.path.join(ROOT, "rulings.json")) as f:
            r = json.load(f)
        return {(v["team"], v["letter"]) for v in r.get("void", [])}, r.get("warnings", []), r.get("penalty_shift_min", {})
    except Exception:
        return set(), [], {}

VOIDED, WARNINGS, SHIFTS = None, None, None

def load_results():
    """{team: [entry, ...]} skipping '__' teams and malformed lines."""
    out = {}
    try:
        names = sorted(os.listdir(RESULTS))
    except OSError:
        return out
    for name in names:
        if not name.endswith(".jsonl"):
            continue
        team = name[:-6]
        if team.startswith("__") or not team:
            continue
        entries = []
        try:
            with open(os.path.join(RESULTS, name)) as f:
                for line in f:
                    line = line.strip()
                    if not line:
                        continue
                    try:
                        e = json.loads(line)
                        if (isinstance(e, dict) and isinstance(e.get("ts"), (int, float))
                                and e.get("letter") and e.get("verdict") in VERDICTS):
                            entries.append(e)
                    except ValueError:
                        continue  # partially-written line
        except OSError:
            continue
        out[team] = entries
    return out


def compute_scoreboard(problems, meta, results, team_names, now):
    start = meta["start_ts"] if meta else None
    global VOIDED, WARNINGS, SHIFTS
    if VOIDED is None or WARNINGS is None or SHIFTS is None:
        VOIDED, WARNINGS, SHIFTS = load_rulings()
    rows = []
    solved_by = {p["letter"]: 0 for p in problems}
    for team in team_names:
        cells = {}
        total_pen = 0
        solved = 0
        for p in problems:
            letter = p["letter"]
            subs = sorted((e for e in results.get(team, []) if e.get("letter") == letter),
                          key=lambda e: e["ts"])
            is_void = (team, letter) in VOIDED
            if is_void and any(e.get("verdict") == "OK" for e in subs):
                cells[letter] = {"s": "void", "attempts": sum(1 for e in subs if e["verdict"] not in ("OK","CE","JE"))}
                continue
            ok = next((e for e in subs if e["verdict"] == "OK"), None)
            fails = sum(1 for e in subs if e["verdict"] not in ("OK", "CE", "JE")
                        and (ok is None or e["ts"] < ok["ts"]))
            n_ce = sum(1 for e in subs if e["verdict"] == "CE")
            n_je = sum(1 for e in subs if e["verdict"] == "JE")
            if ok is not None:
                solved += 1
                solved_by[letter] += 1
                if start is not None:
                    mins = max(0, int((ok["ts"] - start) // 60))
                    shift = SHIFTS.get(team, 0)
                    if shift:
                        mins = max(0, mins - shift)
                else:
                    mins = None
                if start is not None:
                    total_pen += mins + PENALTY_PER_FAIL * fails
                cells[letter] = {"s": "ok", "attempts": fails + 1, "mins": mins,
                                 "clock": time.strftime("%H:%M:%S", time.localtime(ok["ts"]))}
            elif fails:
                cells[letter] = {"s": "fail", "attempts": fails}
            elif n_je:
                cells[letter] = {"s": "je", "attempts": 0}
            elif n_ce:
                cells[letter] = {"s": "ce", "attempts": 0}
            else:
                cells[letter] = {"s": "none", "attempts": 0}
        n_warn = sum(1 for w in WARNINGS if w.get("team") == team)
        n_void = sum(1 for v in VOIDED if v[0] == team)
        rows.append({"team": team, "solved": solved, "penalty": total_pen,
                     "cells": cells, "feedback": has_feedback(team),
                     "warns": n_warn, "voids": n_void})
    rows.sort(key=lambda r: (-r["solved"], r["penalty"]))
    row_nums = {r["team"]: i + 1 for i, r in enumerate(rows)}
    return rows, row_nums, solved_by


def has_feedback(team):
    try:
        return os.path.isfile(os.path.join(TEAMS, team, "feedback.md"))
    except OSError:
        return False


def build_feed(results, row_nums):
    feed = []
    for team, entries in results.items():
        for e in entries:
            feed.append({
                "ts": e["ts"], "team": team, "rank": row_nums.get(team, 0),
                "file": os.path.basename(str(e.get("file", "?"))),
                "letter": e.get("letter", "?"), "verdict": e.get("verdict", "?"),
                "passed": e.get("passed", 0), "total": e.get("total", 0),
                "clock": time.strftime("%H:%M:%S", time.localtime(e["ts"])),
            })
    feed.sort(key=lambda x: x["ts"], reverse=True)
    return feed[:40]


def scan_workspace(team):
    base = os.path.join(TEAMS, team)
    files = []
    if not os.path.isdir(base):
        return files
    for dirpath, dirnames, filenames in os.walk(base):
        dirnames[:] = [d for d in dirnames if not d.startswith(".")]
        for fn in filenames:
            if fn.startswith("."):
                continue
            full = os.path.join(dirpath, fn)
            try:
                st = os.lstat(full)
            except OSError:
                continue
            if st.st_size > MAX_WS_FILE:
                continue
            rel = os.path.relpath(full, base)
            files.append({"path": rel, "mtime": st.st_mtime,
                          "clock": time.strftime("%H:%M:%S", time.localtime(st.st_mtime)),
                          "kb": round(st.st_size / 1024.0, 1)})
    files.sort(key=lambda x: x["mtime"], reverse=True)
    return files[:10]


def build_state():
    now = time.time()
    problems = load_map()
    meta = load_meta(now)
    results = load_results()
    if meta and meta.get("teams"):
        team_names = [t for t in meta["teams"] if not str(t).startswith("__")]
    elif results:
        team_names = sorted(results)
    else:
        team_names = list(DEFAULT_TEAMS)
    rows, row_nums, solved_by = compute_scoreboard(problems, meta, results, team_names, now)
    feed = build_feed(results, row_nums)
    workspaces = {t: scan_workspace(t) for t in team_names}
    diff = [{"letter": p["letter"], "slug": p["slug"], "solvedBy": solved_by[p["letter"]]}
            for p in problems]
    if meta:
        start = meta["start_ts"]
        dur = meta.get("duration_s", 18000)
        elapsed = now - start
        clock = {"mode": "ended" if elapsed >= dur else "running",
                 "elapsed_s": max(0, int(elapsed)),
                 "remaining_s": max(0, int(dur - elapsed)),
                 "duration_s": dur}
    else:
        clock = {"mode": "not_started"}
    return {"generated_at": time.strftime("%H:%M:%S", time.localtime(now)),
            "clock": clock, "problems": problems, "difficulty": diff,
            "rows": rows, "feed": feed, "workspaces": workspaces,
            "has_meta": meta is not None}



AGENTS_DIR = os.path.expanduser(
    "~/.config/pi/agent/sessions/--Users-distiled-codeStuff-cp-cf-pre-icpc-2026--/agents")
ANSI_RE = re.compile(r"\x1b\[[0-9;]*m")

def _pi_wire_for(team):
    """Newest pi subagent wire.jsonl whose prompt names this contestant."""
    best = None
    try:
        entries = os.listdir(AGENTS_DIR)
    except OSError:
        return None
    for d in entries:
        pth = os.path.join(AGENTS_DIR, d, "wire.jsonl")
        if not os.path.isfile(pth):
            continue
        try:
            with open(pth) as f:
                head = f.read(4000)
            if (f"contestant {team} " in head) or (f"You are {team}," in head):
                mt = os.path.getmtime(pth)
                if best is None or mt > best[0]:
                    best = (mt, pth)
        except Exception:
            pass
    return best[1] if best else None

def _wire_lines(path, cap):
    out = []
    try:
        with open(path) as f:
            for line in f:
                try:
                    e = json.loads(line)
                except Exception:
                    continue
                ts = time.strftime("%H:%M:%S", time.localtime(e.get("t", 0) / 1000))
                role = e.get("role", "?")
                for part in e.get("parts") or []:
                    ty = part.get("type")
                    if ty == "text" and part.get("text"):
                        snip = " ".join(str(part["text"]).split())
                        out.append(f"[{ts}] {role}: {snip[:400]}")
                    elif ty == "toolCall":
                        inp = part.get("input") or part.get("args") or {}
                        cmd = ""
                        if isinstance(inp, dict):
                            cmd = str(inp.get("command") or inp.get("prompt") or inp.get("path") or "")[:200]
                        out.append(f"[{ts}]  > {part.get('name', 'tool')} {cmd}")
                if role == "assistant" and e.get("stopReason") == "aborted":
                    out.append(f"[{ts}]  (slice ended; watchdog will resume)")
    except Exception as ex:
        out.append(f"(wire read error: {ex})")
    return out[-cap:]

def team_log(team, cap=90):
    ev = os.path.join(TEAMS, team, "_events.log")
    runner = os.path.join(TEAMS, team, "_runner.log")
    if os.path.isfile(ev):
        try:
            with open(ev, errors="replace") as f:
                lines = [ln.rstrip() for ln in f if ln.strip()]
            return ("events-live", lines[-cap:])
        except Exception as ex:
            return ("events-live", [f"(event log read error: {ex})"])
    if os.path.isfile(runner):
        try:
            with open(runner, errors="replace") as f:
                lines = [ANSI_RE.sub("", ln.rstrip()) for ln in f]
            lines = [ln for ln in lines if ln.strip()]
            lines = [ln for ln in lines
                     if "level=INFO" not in ln and "level=DEBUG" not in ln
                     and "level=WARN" not in ln and "level=ERROR" not in ln]
            return ("opencode", lines[-cap:])
        except Exception as ex:
            return ("opencode", [f"(log read error: {ex})"])
    w = _pi_wire_for(team)
    if w:
        return ("pi-agent", _wire_lines(w, cap))
    return ("none", [f"no transcript found for {team}"])


PAGE = """<!DOCTYPE html>
<html><head><meta charset="utf-8"><title>Pre-ICPC 2026 — AI Model Contest</title>
<style>
:root{--bg:#0d1117;--panel:#161b22;--border:#30363d;--fg:#c9d1d9;--dim:#8b949e;
--green:#238636;--red:#da3633;--orange:#d29922;--purple:#a371f7;--brown:#8e5433;
--gray:#6e7681;--amber:#e3b341}
*{box-sizing:border-box;margin:0;padding:0}
body{background:var(--bg);color:var(--fg);font:13px/1.45 ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;padding:16px}
h1{font-size:18px}h2{font-size:13px;color:var(--dim);text-transform:uppercase;letter-spacing:1px;margin:0 0 8px}
.hdr{display:flex;align-items:baseline;gap:16px;flex-wrap:wrap;margin-bottom:12px}
#clock{font-size:14px;color:var(--orange);font-weight:700}
#badges{display:flex;gap:6px;flex-wrap:wrap}
.badge{background:var(--panel);border:1px solid var(--border);border-radius:10px;padding:1px 8px;font-size:11px}
.badge.fb{border-color:var(--green);color:#3fb950}
.banner{background:#3d2b00;border:1px solid var(--amber);color:var(--amber);padding:6px 10px;border-radius:6px;margin-bottom:12px}
.ended{background:#3d0c11;border-color:var(--red);color:#f85149}
table{border-collapse:collapse;width:max-content;min-width:60%;background:var(--panel);table-layout:fixed;margin:0 auto}
th,td{border:1px solid var(--border);padding:4px 6px;text-align:center;white-space:nowrap}
th{color:var(--dim);font-weight:600}
td.team{text-align:left;font-weight:700;overflow:hidden;text-overflow:ellipsis}
th.pc,td.pc{width:56px;overflow:hidden;text-overflow:ellipsis}
td.pc .cellsub{display:block;overflow:hidden;text-overflow:ellipsis}
td.ok{background:rgba(35,134,54,.55);color:#fff}
td.fail{background:rgba(218,54,51,.4)}
td.je{background:rgba(227,179,65,.35);color:#1c1c1c;font-weight:700}
td.ce{color:var(--gray)}
tr.diff td{background:#0a0e14;color:var(--dim)}
.cellsub{font-size:10px;opacity:.85}
.cols{display:flex;gap:16px;margin-top:16px;flex-wrap:wrap}
.card{background:var(--panel);border:1px solid var(--border);border-radius:6px;padding:10px;flex:1;min-width:420px}
#feed .e{padding:1px 0;border-bottom:1px solid #21262d}
.v-OK{color:#3fb950;font-weight:700}.v-WA{color:#f85149}.v-TL{color:var(--orange)}
.v-ML{color:var(--purple)}.v-RE{color:var(--brown)}.v-CE{color:var(--gray)}.v-JE{color:var(--amber);font-weight:700}
.ws{margin-bottom:10px}.ws h3{font-size:12px;color:#58a6ff}
.ws .f{color:var(--dim)}.ws .f b{color:var(--fg);font-weight:400}
#gen{color:var(--dim);font-size:11px;margin-left:auto}
#logbtns{display:flex;gap:6px;flex-wrap:wrap;margin-bottom:8px}
#logbtns button{background:#21262d;color:var(--fg);border:1px solid var(--border);border-radius:6px;padding:2px 10px;font:inherit;cursor:pointer}
#logbtns button.on{background:#1f6feb;border-color:#1f6feb;color:#fff}
#logbox{max-height:280px;overflow:auto;background:#010409;border:1px solid var(--border);border-radius:6px;padding:8px;font-size:11px;line-height:1.5;white-space:pre-wrap;color:#8b949e}
#logsrc{color:var(--dim);font-weight:400;text-transform:none}
#tabs{margin-left:12px}
.tab{background:#21262d;color:var(--fg);border:1px solid var(--border);border-radius:6px;padding:2px 12px;font:inherit;cursor:pointer}
.tab.on{background:#1f6feb;border-color:#1f6feb;color:#fff}
#probbtns{display:flex;gap:6px;flex-wrap:wrap;margin-bottom:8px}
#probbtns button{background:#21262d;color:var(--fg);border:1px solid var(--border);border-radius:6px;padding:2px 10px;font:inherit;cursor:pointer}
#probbtns button.on{background:#1f6feb;border-color:#1f6feb;color:#fff}
#probbox{background:#010409;border:1px solid var(--border);border-radius:6px;padding:12px;font-size:12px;line-height:1.6;white-space:pre-wrap;color:#c9d1d9}
</style></head><body>
<div class="hdr"><h1>Pre-ICPC 2026 — AI Model Contest</h1><span id="clock">…</span>
<span id="badges"></span><span id="gen"></span>
<span id="tabs"><button class="tab on" onclick="showView('board')">Scoreboard</button><button class="tab" onclick="showView('probs')">Problems</button></span></div>
<div id="banner"></div>
<div id="view-board"><div id="board"></div>
<div class="cols">
<div class="card"><h2>Activity</h2><div id="feed"></div></div>
<div class="card"><h2>Workspace pulse</h2><div id="ws"></div></div>
</div>
<div class="cols"><div class="card" style="min-width:100%"><h2>Live contestant log <span id="logsrc"></span></h2><div id="logbtns"></div><pre id="logbox">pick a contestant above</pre></div></div>
</div>
<div id="view-probs" style="display:none"><div class="card"><h2>Problem statements (contestant sheets)</h2><div id="probbtns"></div><pre id="probbox" style="max-height:none">pick a problem</pre></div></div>
<script>
const esc=s=>String(s).replace(/[&<>]/g,c=>({'&':'&amp;','<':'&lt;','>':'&gt;'}[c]));
function fmtDur(s){s=Math.max(0,s|0);const h=s/3600|0,m=(s%3600)/60|0,x=s%60;
 return String(h).padStart(2,'0')+':'+String(m).padStart(2,'0')+':'+String(x).padStart(2,'0');}
function cellHtml(c,hasMeta){
 if(!c||c.s==='none')return '<td class=pc></td>';
 if(c.s==='ok'){const t=hasMeta?esc(c.mins):esc(c.clock);
  return `<td class="ok pc">${t}<div class="cellsub">${c.attempts} try</div></td>`;}
 if(c.s==='fail')return `<td class="fail pc">${c.attempts}</td>`;
 if(c.s==='je')return '<td class="je pc">!</td>';
 if(c.s==='ce')return '<td class="ce pc">CE</td>';
 if(c.s==='void')return `<td class="ce" style="text-decoration:line-through" title="VOID by rulings.json (${c.attempts} tries)">✗ VOID</td>`;
 return '<td></td>';}
async function tick(){try{
 const r=await fetch('/api/state');const st=await r.json();
 // clock
 let cl='';
 if(st.clock.mode==='running')cl=`${fmtDur(st.clock.elapsed_s)} elapsed / ${fmtDur(st.clock.remaining_s)} left`;
 else if(st.clock.mode==='ended')cl='CONTEST ENDED';
 document.getElementById('clock').textContent=cl;
 document.getElementById('banner').innerHTML=
  st.clock.mode==='not_started'?'<div class="banner">contest not started (no meta.json)</div>':
  st.clock.mode==='ended'?'<div class="banner ended">CONTEST ENDED</div>':'';
 document.getElementById('gen').textContent='updated '+st.generated_at;
 document.getElementById('badges').innerHTML=st.rows.map(r=>
  `<span class="badge ${r.feedback?'fb':''}">${esc(r.team)}${r.feedback?' · feedback in':''}</span>`).join('');
 // scoreboard
 let h='<table><colgroup>'
  +'<col style="width:40px"><col style="width:210px"><col style="width:64px"><col style="width:76px"><col style="width:86px">'
  +'<col style="width:56px">'.repeat(st.problems.length)
  +'</colgroup><tr><th>#</th><th>team</th><th>solved</th><th>pen</th><th title="warnings / voided problems (rulings.json)">warn</th>';
 for(const p of st.problems)h+=`<th class="pc" title="${esc(p.slug)}">${esc(p.letter)}</th>`;
 h+='</tr>';
 st.rows.forEach((r,i)=>{h+=`<tr><td>${i+1}</td><td class="team">${esc(r.team)}</td>`+
  `<td>${r.solved}</td><td>${r.penalty}</td>`+
  `<td style="color:${(r.warns||r.voids)?'var(--amber)':'var(--gray)'}">${r.warns||0}w ${r.voids||0}v</td>`;
  for(const p of st.problems)h+=cellHtml(r.cells[p.letter],st.has_meta);
  h+='</tr>';});
 h+='<tr class="diff"><td colspan="5">solved by</td>';
 for(const d of st.difficulty)h+=`<td title="${esc(d.slug)}">${d.solvedBy}</td>`;
 h+='</tr></table>';
 document.getElementById('board').innerHTML=h;
 // feed
 document.getElementById('feed').innerHTML=st.feed.map(e=>
  `<div class="e">[${e.clock}] <b>${e.rank?('#'+e.rank+' '):''}${esc(e.team)}</b> `+
  `${esc(e.file)} → <b>${esc(e.letter)}</b>: <span class="v-${esc(e.verdict)}">${esc(e.verdict)}</span> `+
  `<span style="color:var(--dim)">(${e.passed}/${e.total})</span></div>`).join('')||'<span style="color:var(--dim)">no submissions yet</span>';
 // workspaces
 document.getElementById('ws').innerHTML=Object.entries(st.workspaces).map(([t,fs])=>
  `<div class="ws"><h3>${esc(t)}</h3>`+(fs.length?fs.map(f=>
   `<div class="f">${f.clock} <b>${esc(f.path)}</b> ${f.kb} KB</div>`).join(''):
   '<div class="f">no files</div>')+'</div>').join('');
 // log buttons
 document.getElementById('logbtns').innerHTML=st.rows.map(r=>
  `<button class="${r.team===logTeam?'on':''}" onclick="logTeam='${esc(r.team)}';tickLog()">${esc(r.team)}</button>`).join('');
}catch(e){/* keep polling */}}
let logTeam=null;
let logSrc='';
async function tickLog(){if(!logTeam)return;try{
 const r=await fetch('/api/log?team='+encodeURIComponent(logTeam));const d=await r.json();
 const el=document.getElementById('logbox');
 var tail='';
 if(d.proc_alive===false)tail='\\n\\n-- no live opencode process for this team (waiting for watchdog respawn) --';
 else if(d.log_age_s!=null&&d.log_age_s>40)tail='\\n\\n-- agent alive; log quiet for '+d.log_age_s+'s (long silent generation in progress) --';
 el.textContent=(d.lines&&d.lines.length?d.lines.join('\\n'):'no transcript captured yet')+tail;
 document.getElementById('logsrc').textContent=d.source?('['+d.source+']'):'';
 el.scrollTop=el.scrollHeight;
 document.getElementById('logbtns').querySelectorAll('button').forEach(b=>
  b.classList.toggle('on',b.textContent===logTeam));
}catch(e){}}
let curProb=null;
function showView(v){
 document.getElementById('view-board').style.display=v==='board'?'':'none';
 document.getElementById('view-probs').style.display=v==='probs'?'':'none';
 document.querySelectorAll('.tab').forEach((b,i)=>b.classList.toggle('on',(i===0)===(v==='board')));
 if(v==='probs')tickProbs();
}
async function tickProbs(){
 const r=await fetch('/api/state');const st=await r.json();
 document.getElementById('probbtns').innerHTML=st.problems.map(p=>
  `<button class="${p.letter===curProb?'on':''}" onclick="curProb='${p.letter}';tickProbText()">${p.letter}</button>`).join('')+
  `<span style="color:var(--dim);margin-left:8px">${curProb?('solved by '+(st.difficulty.find(d=>d.letter===curProb)||{}).solvedBy+' of '+st.rows.length):''}</span>`;
}
async function tickProbText(){
 if(!curProb)return;
 const r=await fetch('/api/problem?letter='+curProb);const d=await r.json();
 document.getElementById('probbox').textContent=d.text||'no sheet';
 tickProbs();
}
tick();setInterval(tick,5000);setInterval(tickLog,5000);
</script></body></html>"""


class Handler(BaseHTTPRequestHandler):
    server_version = "ContestDash/1.0"

    def log_message(self, *args):
        pass

    def _send(self, code, body, ctype):
        data = body.encode("utf-8")
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(data)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(data)

    def do_GET(self):
        path = self.path.split("?", 1)[0]
        if path == "/" or path == "/index.html":
            self._send(200, PAGE, "text/html; charset=utf-8")
        elif path == "/api/state":
            try:
                self._send(200, json.dumps(build_state()), "application/json")
            except Exception as exc:  # never 500 the poller
                self._send(200, json.dumps({"error": str(exc)}), "application/json")
        elif path == "/api/problem":
            try:
                from urllib.parse import urlparse, parse_qs
                letter = parse_qs(urlparse(self.path).query).get("letter", [""])[0].upper()
                ppath = os.path.join(ROOT, "problems", f"{letter}.txt")
                if letter and os.path.isfile(ppath):
                    with open(ppath, errors="replace") as f:
                        self._send(200, json.dumps({"letter": letter, "text": f.read()}),
                                   "application/json")
                else:
                    self._send(200, json.dumps({"letter": letter, "text": "no such sheet"}),
                               "application/json")
            except Exception as exc:
                self._send(200, json.dumps({"text": f"error: {exc}"}), "application/json")
        elif path == "/api/log":
            try:
                from urllib.parse import urlparse, parse_qs
                team = parse_qs(urlparse(self.path).query).get("team", [""])[0]
                src, lines = team_log(team)
                team_model_frag = {"kimi-k3": "my-local-server/kimi-k3",
                                   "glm-5.3": "my-local-server/glm-5.3"}.get(team)
                frag = team_model_frag or team
                alive = subprocess.run(
                    ["pgrep", "-f", f"opencode run -.*{frag}"],
                    capture_output=True).returncode == 0
                runner = os.path.join(TEAMS, team, "_events.log")
                if not os.path.isfile(runner):
                    runner = os.path.join(TEAMS, team, "_runner.log")
                age = None
                if os.path.isfile(runner):
                    age = int(time.time() - os.path.getmtime(runner))
                self._send(200, json.dumps({"team": team, "source": src,
                                            "lines": lines, "proc_alive": alive,
                                            "log_age_s": age}), "application/json")
            except Exception as exc:
                self._send(200, json.dumps({"error": str(exc), "lines": []}),
                           "application/json")
        else:
            self._send(404, "not found", "text/plain")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", type=int, default=8777)
    args = ap.parse_args()
    httpd = ThreadingHTTPServer(("0.0.0.0", args.port), Handler)
    print(f"dashboard on http://localhost:{args.port} (root {ROOT})", flush=True)
    httpd.serve_forever()


if __name__ == "__main__":
    main()
