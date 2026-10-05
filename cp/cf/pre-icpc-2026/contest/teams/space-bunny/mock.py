import subprocess, sys
def run(N, verbose=False):
    # complete tree with N nodes: node at level L position p (1..2^L) exists iff N >= 2^L + p - 1
    def exists(level, pos):
        return N >= (1 << level) + pos - 1
    inp = "1\n"
    p = subprocess.Popen(["./c"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True, bufsize=1)
    p.stdin.write("1\n"); p.stdin.flush()
    cur = []  # list of 'L'/'R'
    nq = 0
    while True:
        line = p.stdout.readline()
        if not line: return None, nq, "EOF"
        line = line.strip()
        if line.startswith('!'):
            got = int(line.split()[1])
            return got, nq, ("OK" if got == N else "WRONG")
        if not line.startswith('?'):
            return None, nq, "BAD:"+line
        d = line.split()[1]
        nq += 1
        if nq > 20000: return None, nq, "TOOMANY"
        lvl = len(cur)
        if d == 'B':
            if lvl == 0: ok = 0
            else: cur.pop(); ok = 1
        else:
            if d == 'L': pos = 1 + 2*0  # recompute below
            # position of the child: parent position p at level l -> left child pos 2p-1, right 2p
            if lvl == 0: ppos = 1
            else:
                # parent position
                ppos = 1
                for ch in cur: ppos = 2*ppos - 1 if ch == 'L' else 2*ppos
            cpos = 2*ppos - 1 if d == 'L' else 2*ppos
            ok = 1 if exists(lvl+1, cpos) else 0
            if ok: cur.append(d)
        p.stdin.write(f"{ok}\n"); p.stdin.flush()
    return None, nq, "LOOP"
for N in [1,2,3,4,5,6,7,8,9,15,16,17,100,1000,2**20-1,2**20,2**20+5,2**40-1,2**59-1,2**59,10**18,2**60-1,123456789012345]:
    got, nq, st = run(N)
    flag = "ok" if st=="OK" else "FAIL"
    print(f"N={N}: got={got} queries={nq} {flag} {'' if st=='OK' else st}")
