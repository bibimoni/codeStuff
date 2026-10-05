# STRATEGY — kimi-k3 (FINAL: 13/13 solved, elapsed ~36 min)

Final rank snapshot: #2 of 13 (penalty 242; leader 83). All problems OK on judge.

| P | Slug | Status | Key idea |
|---|------|--------|----------|
| A | suffix-array | OK | min alphabet = 1 + #{i: rank[p_i+1] > rank[p_{i+1}+1]} (rank[n+1]=-inf); -1 impossible (verified exhaustively n<=5) |
| B | grid-reboot | OK | GF(2): (A+I)x = ~s; one Gauss-Jordan on [M\|I] bitset<6005>, per query c=Tb + pivot readout; 0.08s worst |
| C | the-hidden-cave | OK | interactive: walk L for depth h; binary search rightmost node on level h via path bits; ~7k queries max of 8000 |
| D | mulgame | OK | losing intervals (9*18^i, 18^{i+1}]: while n>18 n=ceil(n/18); n<=9 => first wins (brute-verified to 2e5) |
| E | scheduling | OK | SUM over flexible orientations of #LE = #LE of FIXED-edges forest! (each perm forces unique orientation). Mixed-orientation tree LE count via rank-distribution DP: F[a]·G[b] merge, j=elements of child before v: ways=C(a+j,j)*C(szA-1-a+szB-j,szB-j), case v<c: j<=b, case c<v: j>b; prefix/suffix sums of G. O(n^2), mod 998244353. Brute-checked 900 trees. |
| F | snow-white | OK | height with count==7 |
| G | self-crossing-turtle | OK | canonical LC335 3 conditions on i-2/i-3/i-4/i-5 |
| H | rlu-cache-easy | OK | pbds order_of_key on timestamps + key<->ts maps; r = size - order_of_key(ts+1) + 1 |
| I | coolant-loops | OK | cycle rank = E-V+C, reverse vertex-add with DSU; edge added when neighbor present & mutually open |
| J | dp-counting-med | OK | S==0: 2^{#interior zero prefix sums}; S!=0: candidates T|S among prefix values, tuple count via per-T two-pointer DP over occurrences of jT |
| K | zero-segment | OK | closure of paid set P = [minP,maxP]; k==1: min a_i; else min a_i+a_j over j-i>=k-1 |
| L | coral-loop | OK | 3x-linearized ring; pref(i)=sum a(k<i); G=b+pref, F=b-pref; segtree (minG,minF,minPair=min_i<j G_i+F_j), lazy pref-add (a-update -> [e+1,m] x3 copies); answer = min(Acw, Accw, Acw+Q(X), Accw+Q(Y), C1=(minG[s0,t0-1]-ps)+(minG[t0,s0+n-1]-pt), C2=(minF[t0+1,s0+n]+psn)+(minF[s0+1,t0]+pt)). Nook: min(minG[S,S+n-1]-pS, minF[S-n+1,S]+pS). |
| M | dp-counting-med2 | OK (1 WA: window-sum cap corruption, fixed w/ __int128) | Mahonian f[n][m] sliding window; greedy k-th lex: placing j-th smallest remaining adds j inversions |

Single failure this contest: M first submission had capped sliding-window sums (wsum capped at 4e18 then subtracted from) -> wrong small values. Fix: __int128 accumulator.

Contest effectively over for me: 13/13 OK, penalty fixed. feedback.md written at stop.
