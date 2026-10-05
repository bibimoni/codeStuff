import subprocess, random, sys

def run_one(N, timeout=30):
    # simulate interaction for a single test
    proc = subprocess.Popen(['./Ctest'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, bufsize=1)
    # initial T is already consumed? program reads T first — we send T=1 at start
    # We'll drive: write "1\n", then loop reading queries
    def rd():
        line = proc.stdout.readline()
        if not line:
            return None
        return line.strip()
    def send(s):
        proc.stdin.write(s + '\n')
        proc.stdin.flush()
    send('1')
    q = 0
    cur = 1  # heap index
    while True:
        line = rd()
        if line is None:
            err = proc.stderr.read()
            return 'died', q, err
        if line.startswith('!'):
            ans = int(line.split()[1])
            proc.stdin.close()
            rc = proc.wait(timeout=5)
            return (ans == N), q, rc
        assert line.startswith('?'), line
        d = line.split()[1]
        q += 1
        if q > 8000:
            proc.kill()
            return 'overflow', q, ''
        if d == 'B':
            if cur == 1:
                send('0')
            else:
                cur //= 2
                send('1')
        elif d == 'L':
            if cur * 2 <= N:
                cur *= 2
                send('1')
            else:
                send('0')
        else:  # R
            if cur * 2 + 1 <= N:
                cur = cur * 2 + 1
                send('1')
            else:
                send('0')

cases = [1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 16, 17, 31, 32, 33, 63, 64, 100, 1000, 1000000,
         (1 << 60) - 1, 1 << 60, (1 << 60) + 12345, 10**18, 10**18 - 1, 10**18 - 7,
         2**59, 2**59 + 1, 999999999999999999]
random.seed(1)
cases += [random.randint(1, 10**18) for _ in range(25)]
bad = 0
maxq = 0
for N in cases:
    ok, q, info = run_one(N)
    if isinstance(q, int): maxq = max(maxq, q)
    if ok is not True:
        bad += 1
        print('FAIL N', N, 'ok', ok, 'q', q, 'info', str(info)[:200])
        if bad > 5: sys.exit(1)
    else:
        print('ok N', N, 'queries', q)
print('C checked', len(cases), 'bad', bad, 'max queries', maxq)
sys.exit(1 if bad else 0)
