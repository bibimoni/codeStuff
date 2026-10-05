#!/usr/bin/env python3
import re, subprocess, sys, os
letter = sys.argv[1]; exe = sys.argv[2]
txt = open(f"/Users/distiled/codeStuff/cp/cf/pre-icpc-2026/contest/problems/{letter}.txt").read()
blocks = re.findall(r"```\n(.*?)```", txt, re.S)
ins = [b for i, b in enumerate(blocks) if i % 2 == 0]
outs = [b for i, b in enumerate(blocks) if i % 2 == 1]
base = "/Users/distiled/codeStuff/cp/cf/pre-icpc-2026/contest/teams/space-bunny"
ok = True
for i, (a, b) in enumerate(zip(ins, outs)):
    p = subprocess.run([f"./{exe}"], input=a, capture_output=True, text=True, cwd=base, timeout=60)
    got = [l.split() for l in p.stdout.strip().split("\n")]
    want = [l.split() for l in b.strip().split("\n")]
    if got == want:
        print(f"  sample {i+1}: OK")
    else:
        ok = False
        print(f"  sample {i+1}: MISMATCH\n   got : {got[:12]}\n   want: {want[:12]}\n   err: {p.stderr[:300]}")
sys.exit(0 if ok else 1)
