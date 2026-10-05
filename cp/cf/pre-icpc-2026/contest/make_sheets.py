#!/usr/bin/env python3
"""Generate contestant-facing problem sheets into contest/problems/<L>.txt
and the letter map contest/map.txt. Reads statements/limits via API and
sample tests from contest/_judge/<L>/tests/."""

import json, os, subprocess

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOL = os.path.join(ROOT, "polygon_tool.py")
J = os.path.join(ROOT, "contest", "_judge")
OUT = os.path.join(ROOT, "contest", "problems")

IDS = [
    ("A", 585864, "suffix-array"), ("B", 585524, "grid-reboot"),
    ("C", 584556, "the-hidden-cave"), ("D", 586686, "mulgame"),
    ("E", 586674, "scheduling"), ("F", 586329, "snow-white"),
    ("G", 586335, "self-crossing-turtle"), ("H", 586694, "rlu-cache-easy"),
    ("I", 586459, "coolant-loops"), ("J", 584874, "dp-math-hard"),
    ("K", 581736, "zero-segment"), ("L", 590582, "coral-loop"),
]

def api(method, **params):
    r = subprocess.run(["python3", TOOL, method] + [f"{k}={v}" for k, v in params.items()],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        raise RuntimeError(f"{method} {params}: {r.stdout[-200:]}")
    return json.loads(r.stdout)

def tname(i):
    return f"{i:02d}"

os.makedirs(OUT, exist_ok=True)
map_lines = []
for letter, pid, slug in IDS:
    info = api("problem.info", problemId=pid)["result"]
    tl, ml = info["timeLimit"], info["memoryLimit"]
    st = api("problem.statements", problemId=pid)["result"].get("english", {})
    inter = info.get("interactive", False)
    samples = []
    try:
        tests = api("problem.tests", problemId=pid, testset="tests")["result"]
        samples = [t["index"] for t in tests if t.get("useInStatements")]
    except Exception:
        pass
    parts = [
        f"# Problem {letter} — {st.get('name') or slug}",
        f"Time limit: {tl/1000:g}s per test | Memory limit: {ml} MB" +
        (" | INTERACTIVE problem (see protocol)" if inter else ""),
        "",
        "## Statement",
        st.get("legend", "").strip(),
        "",
        "## Input",
        st.get("input", "").strip(),
        "",
        "## Output",
        st.get("output", "").strip(),
    ]
    if inter and st.get("interaction"):
        parts += ["", "## Interaction protocol", st["interaction"].strip()]
    if st.get("notes", "").strip():
        parts += ["", "## Notes", st["notes"].strip()]
    tdir = os.path.join(J, letter, "tests")
    for si, idx in enumerate(samples, 1):
        ip, ap = os.path.join(tdir, tname(idx)), os.path.join(tdir, tname(idx) + ".a")
        if os.path.exists(ip) and os.path.exists(ap):
            parts += ["", f"## Example {si} — input", "```",
                      open(ip).read().strip(), "```",
                      f"## Example {si} — output", "```",
                      open(ap).read().strip(), "```"]
    open(os.path.join(OUT, f"{letter}.txt"), "w").write("\n".join(parts) + "\n")
    map_lines.append(f"{letter} {pid} {slug} tl={tl} ml={ml} inter={int(inter)} samples={len(samples)} tests_dir={tdir}")
    print(f"{letter}: {slug} tl={tl}ml={ml} samples={len(samples)}")
open(os.path.join(ROOT, "contest", "map.txt"), "w").write("\n".join(map_lines) + "\n")
print("map.txt written")
