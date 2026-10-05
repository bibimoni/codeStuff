import subprocess

CASES = [1, 2, 3, 6, 7, 8, 999999999999999999, 10**18]
p = subprocess.Popen(["/tmp/gpt-sol-C"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True, bufsize=1)
p.stdin.write(str(len(CASES)) + "\n")
p.stdin.flush()
for n in CASES:
    node = 1
    queries = 0
    while True:
        line = p.stdout.readline().strip()
        if line.startswith("!"):
            assert int(line.split()[1]) == n, (n, line)
            break
        assert line.startswith("? "), line
        queries += 1
        assert queries <= 8000, (n, queries)
        move = line[2]
        nxt = node // 2 if move == "B" else node * 2 + (move == "R")
        ok = move == "B" and node > 1 or move != "B" and nxt <= n
        if ok:
            node = nxt
        p.stdin.write(str(int(ok)) + "\n")
        p.stdin.flush()
p.stdin.close()
assert p.wait(timeout=2) == 0
print("C mock OK")
