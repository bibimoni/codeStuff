#!/usr/bin/env python3
"""Minimal Polygon API client.

Auth: reads Key/Secret from a secret file (default: <this dir>/secret,
override with env POLYGON_SECRET_FILE). Secret file format: lines like
    Name:   <polygon handle>
    Key:    <api key>
    Secret: <api secret>

Usage:
    polygon_tool.py <method> [k=v ...]
    - values may reference files:  legend=@stmt/legend.tex  (content is read)
    - prints response body: pretty JSON if it parses, raw text otherwise
    - exit code 0 on status OK / non-JSON 200, 1 on FAILED / HTTP error
Examples:
    polygon_tool.py problems.list
    polygon_tool.py problem.create name=a-plus-b
    polygon_tool.py problem.saveStatement problemId=123 lang=english name="A+B" legend=@legend.tex
    polygon_tool.py problem.saveFile problemId=123 type=source name=validator.cpp file=@validator.cpp sourceType=cpp.g++17
"""
import hashlib, json, os, random, string, sys, time
import urllib.parse, urllib.request

BASE = "https://polygon.codeforces.com/api/"

def creds():
    path = os.environ.get("POLYGON_SECRET_FILE",
                          os.path.join(os.path.dirname(os.path.abspath(__file__)), "secret"))
    key = secret = None
    with open(path) as f:
        for line in f:
            k, _, v = line.partition(":")
            k, v = k.strip().lower(), v.strip()
            if k == "key": key = v
            elif k == "secret": secret = v
    if not key or not secret:
        sys.exit("secret file must contain Key: and Secret: lines")
    return key, secret

def call(method, params):
    key, secret = creds()
    params = {k: str(v) for k, v in params.items()}
    params["apiKey"] = key
    params["time"] = str(int(time.time()))
    rand = "".join(random.choice(string.ascii_lowercase + string.digits) for _ in range(6))
    # Polygon signs the RAW (unencoded) sorted key=value& string; body is urlencoded.
    qs = "&".join(f"{k}={params[k]}" for k in sorted(params))
    sig_src = f"{rand}/{method}?{qs}#{secret}"
    sig = rand + hashlib.sha512(sig_src.encode()).hexdigest()
    body = urllib.parse.urlencode({**params, "apiSig": sig}).encode()
    req = urllib.request.Request(BASE + method, data=body)
    with urllib.request.urlopen(req, timeout=300) as r:
        raw = r.read()
    if os.environ.get("POLYGON_RAW_OUT"):
        with open(os.environ["POLYGON_RAW_OUT"], "wb") as f:
            f.write(raw)
        return '{"status": "OK", "comment": "wrote ' + os.environ["POLYGON_RAW_OUT"] + '"}'
    return raw.decode()

def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    method = sys.argv[1]
    params = {}
    for arg in sys.argv[2:]:
        k, _, v = arg.partition("=")
        if v.startswith("@"):
            with open(v[1:]) as f: v = f.read()
        params[k] = v
    try:
        out = call(method, params)
    except urllib.error.HTTPError as e:
        print("HTTP %s: %s" % (e.code, e.read().decode()[:4000]), file=sys.stderr)
        sys.exit(1)
    try:
        obj = json.loads(out)
        print(json.dumps(obj, indent=2, ensure_ascii=False)[:20000])
        if obj.get("status") != "OK":
            sys.exit(1)
    except json.JSONDecodeError:
        print(out[:20000])  # plain-text methods (viewFile, script, ...)

if __name__ == "__main__":
    main()
