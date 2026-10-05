#!/usr/bin/env python3
"""Final scoreboard for the Pre-ICPC 2026 AI Model Contest.
ICPC rules: rank by solved desc, then penalty asc. Applies contest/rulings.json:
voided (team,letter) never count; penalty_shift_min shifts minutes-to-OK for
late-joining teams; CE/JE never count as attempts."""
import json, os, time, datetime, statistics, sys

ROOT = os.path.dirname(os.path.abspath(__file__))

def load_map():
    probs = []
    for line in open(os.path.join(ROOT, "map.txt")):
        p = line.split()
        probs.append({"letter": p[0], "slug": p[2]})
    return probs

def load_results():
    out = {}
    rd = os.path.join(ROOT, "results")
    for name in os.listdir(rd):
        team = name[:-6]
        if name.endswith(".jsonl") and not team.startswith("__"):
            rows = []
            for l in open(os.path.join(rd, name), errors="replace"):
                try:
                    r = json.loads(l)
                    if isinstance(r.get("ts"), (int, float)) and r.get("letter"):
                        rows.append(r)
                except Exception:
                    continue
            out[team] = rows
    return out

def main():
    meta = json.load(open(os.path.join(ROOT, "meta.json")))
    try: rulings = json.load(open(os.path.join(ROOT, "rulings.json")))
    except FileNotFoundError: rulings = {}
    start = meta["start_ts"]
    voided = {(v["team"], v["letter"]) for v in rulings.get("void", [])}
    warns = rulings.get("warnings", [])
    shifts = rulings.get("penalty_shift_min", {})
    problems = load_map()
    results = load_results()
    teams = [t for t in meta["teams"] if t in results]

    board, prob_stats = [], {p["letter"]: {"solved_by": [], "attempts": 0, "first_ok_min": []}
                             for p in problems}
    for team in teams:
        solved, pen = 0, 0
        timeline = []
        for p in problems:
            L = p["letter"]
            subs = sorted((r for r in results.get(team, []) if r["letter"] == L), key=lambda r: r["ts"])
            prob_stats[L]["attempts"] += len(subs)
            oks = [r for r in subs if r["verdict"] == "OK"]
            ok = next((r for r in oks if (team, L) not in voided or r["ts"] == oks[0]["ts"]), None)
            # void: the FIRST OK is disqualified; honour none.
            if (team, L) in voided:
                ok = None
            if ok is None and any(r["verdict"] == "OK" for r in subs) and (team, L) in voided:
                pass  # real OK existed but is void
            if ok:
                of = next(r for r in subs if r["verdict"] == "OK")
                fails = sum(1 for r in subs if r["verdict"] not in ("OK", "CE", "JE") and r["ts"] < of["ts"])
                mins = max(0, int((ok["ts"] - start) // 60) - shifts.get(team, 0))
                solved += 1
                pen += mins + 20 * fails
                prob_stats[L]["solved_by"].append(team)
                prob_stats[L]["first_ok_min"].append(max(0, int((ok["ts"] - start) // 60)))
                timeline.append((mins, L, fails))
        board.append({"team": team, "solved": solved, "penalty": pen,
                      "warns": sum(1 for w in warns if w.get("team") == team),
                      "voids": sum(1 for v in voided if v[0] == team),
                      "timeline": sorted(timeline)})
    board.sort(key=lambda r: (-r["solved"], r["penalty"]))
    json.dump({"start": start, "board": board, "prob_stats": prob_stats}, sys.stdout, indent=1)

if __name__ == "__main__":
    main()
