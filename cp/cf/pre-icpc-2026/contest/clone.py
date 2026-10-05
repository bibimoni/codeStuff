#!/usr/bin/env python3
"""Clone all contest problems from Polygon into contest/_judge/<letter>/.

Steps per problem: buildPackage(full=true, verify=false) -> poll READY ->
download linux package -> unzip. Log lines to stdout.
"""
import json, os, subprocess, sys, time, zipfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOL = os.path.join(ROOT, "polygon_tool.py")
JUDGE_DIR = os.path.join(ROOT, "contest", "_judge")

IDS = [
    ("A", 585864), ("B", 585524), ("C", 584556), ("D", 586686),
    ("E", 586674), ("F", 586329), ("G", 586335), ("H", 586694),
    ("I", 586459), ("J", 584874), ("K", 581736), ("L", 590582),
]

def api_raw(method, params, out_path=None):
    env = dict(os.environ)
    if out_path:
        env["POLYGON_RAW_OUT"] = out_path
    r = subprocess.run(["python3", TOOL, method] + [f"{k}={v}" for k, v in params.items()],
                       capture_output=True, text=True, env=env, cwd=ROOT)
    if r.returncode != 0:
        raise RuntimeError(f"{method} failed: {r.stdout[-300:]} {r.stderr[-300:]}")
    return json.loads(r.stdout)

def api(method, **params):
    return api_raw(method, params)

def latest_ready(pid):
    packs = api("problem.packages", problemId=pid)["result"]
    ready = [p for p in packs if p["state"] == "READY"]
    return max(ready, key=lambda p: p["revision"], default=None)

def main():
    os.makedirs(JUDGE_DIR, exist_ok=True)
    # 1. kick off full builds
    for letter, pid in IDS:
        try:
            api("problem.buildPackage", problemId=pid, full="true", verify="false")
            print(f"[{letter}] {pid} build started", flush=True)
        except Exception as e:
            print(f"[{letter}] {pid} build start failed: {e}", flush=True)
        time.sleep(1)
    # 2. poll + download each
    pending = dict(IDS)
    deadline = time.time() + 3600
    while pending and time.time() < deadline:
        for letter, pid in list(pending.items()):
            try:
                pkg = latest_ready(pid)
                if not pkg:
                    continue
                zip_path = os.path.join(JUDGE_DIR, f"{letter}.zip")
                if not os.path.exists(zip_path):
                    api_raw("problem.package",
                            {"problemId": pid, "packageId": pkg["id"], "type": "linux"},
                            out_path=zip_path)
                    with open(zip_path, "rb") as f:
                        if f.read(2) != b"PK":
                            os.remove(zip_path)
                            raise RuntimeError("not a zip (linux variant not ready)")
                dest = os.path.join(JUDGE_DIR, letter)
                os.makedirs(dest, exist_ok=True)
                with zipfile.ZipFile(zip_path) as z:
                    z.extractall(dest)
                ntests = len([f for f in os.listdir(os.path.join(dest, "tests")) if not f.endswith(".a")]) \
                    if os.path.isdir(os.path.join(dest, "tests")) else -1
                print(f"[{letter}] {pid} cloned: pkg {pkg['id']} rev {pkg['revision']}, tests={ntests}", flush=True)
                del pending[letter]
            except Exception as e:
                print(f"[{letter}] {pid} pending: {str(e)[:160]}", flush=True)
        if pending:
            time.sleep(15)
    for letter, pid in pending.items():
        print(f"[{letter}] {pid} TIMEOUT/FAIL", flush=True)
    print("DONE", flush=True)

if __name__ == "__main__":
    main()
