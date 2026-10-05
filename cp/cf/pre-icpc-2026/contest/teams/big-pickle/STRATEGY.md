# big-pickle STRATEGY (contest started ~23:44, 5h)

Status legend: TODO / WIP / submitted / OK / WA

| L | slug | diff | status | approach |
|---|------|------|--------|----------|
| A | suffix-array | easy | OK 103/103 | min distinct chars = 1 + #{i : rk[p_i+1] >= rk[p_{i+1}+1]} |
| B | grid-reboot | med | OK 101/101 | GF(2) bitset Gauss-Jordan on [A\|I]; keep T columns, y=T*b per query; free vars 0 |
| C | the-hidden-cave | med | OK 15/15 | leftmost descent -> h; binary search c (last-level size) with path-cached nav; N=2^h-1+c. <=3700 queries |
| D | mulgame | easy | OK 101/101 | losing iff n in (9*18^{i-1}, 18^i]; i = min with 18^i >= n |
| E | scheduling | med | OK 101/101 | sum over w=0 orientations = #perms respecting w=1/2 edges; rank-DP on tree, dp[v][k], merge child via suffix/prefix sums of dp[c] |
| F | snow-white | easy | OK 102/102 | trivial: the height occurring exactly 7 times |
| G | self-crossing-turtle | easy | OK 19/19 | only need pairs (i,i+3),(i,i+4),(i,i+5) |
| H | rlu-cache-easy | med | OK 24/24 | Fenwick over touch-timestamps + deque for LRU eviction; rank = active - pref(ts) |
| I | coolant-loops | easy-med | OK 34/34 | reverse DSU: independent loops = E - V + C after each reverse-add |
| J | dp-math-hard | med | OK 34/34 | per k|S: group DP over prefix-sum value-lists; S==0 -> 2^(#zero prefixes) |
| K | zero-segment | easy-med | OK 40/40 | zeros spread only between two paid zeros => min over y-x+1>=k of a_x+a_y; k=1 -> min a |
| L | coral-loop | hard | OK 42/42 | P[i]=prefix, A=P+b, V=b-P; lazy segtree (minA,minV,minPair=min_{i<j}A[i]+V[j]); 9 island cases + 5 Nook cases |
| M | dp-counting-med | easy-med | OK 34/34 | f[len][inv] inversions DP (sat 4e18), lex unranking over remaining values |

## Key formulas / notes

**A**: rank[n+1] = -1 (empty suffix smallest). Adjacent ranks i,i+1 may share a char iff
rk[p_i+1] < rk[p_{i+1}+1]. Distinct count = 1 + number of adjacent pairs where that fails.
Never -1 (all-distinct always works). Verified on samples 1/2/3.

**D**: win/lose boundaries multiply by 2,9,2,9,... from 9. Losing = (9*18^{i-1}, 18^i].

**K**: rake needs BOTH supports zero to zero the middle. Zero set after closure = [minZ,maxZ].
So >= 2 paid positions, cost = a_x + a_y, need y-x+1 >= k => sliding-window min prefix.
k=1: just min a_i.

**J**: split valid iff P[i_j] = j*S/k for cut indices. Candidate k: divisors of |S| with k<=n.
For each c=S/k: count increasing index chains through value-groups {c,2c,...}. S=0: cuts only at
zero prefixes => 2^z.

**B**: Gauss-Jordan on [A | I] with A = I + adj. Must keep T's *columns* (TT[j] = col j of T)
so y = T*b is a cheap per-query XOR. Non-pivot rows of R must give y_i = 0 else -1.
Bugs hit: XOR-ing full rows of A gives b^T*T (wrong); resetting y with ^= instead of clearing.
No `t` header on B - it is a single instance. Queries may be "0101" or "0 1 0 1" tokens.

**H**: key timestamps start at 1..n (key 1 = LRU = order n). Rank = active - pref(ts-1).
active is ALWAYS n (insert either replaces or evicts-then-inserts), so no bookkeeping needed.
Deque of (keyidx, ts) in increasing ts order; lazily drop stale fronts to find the LRU.

**I**: reverse-add DSU. Junction with exactly 1 opening is impossible per statement (validator
rejects it) - generate only 0 or 2/3/4 openings in stress.

**E**: w=0 edges impose no constraint (each permutation orients them uniquely) => answer =
#linear extensions of the w=1/2 oriented subgraph. Nodes can have MANY forced predecessors,
so NO forest hook-length (verified: wrong on ~25% of random cases). Instead tree DP:
dp[v][k] = #orders of subtree(v) with v at 0-idx pos k. Merging child c into acc at v:
for each t (#elems of T_c before v), R[t] = sum of dp[c][i] over i<t (c before v) or i>=t
(v before c) or W_c for all t (free edge). Then
new[k+t] += acc[k]*R[t]*C(k+t,k)*C(s-1-k+b-t,s-1-k). O(n^2), 0.14s at n=4000.

## Log
- 23:44 start, read all 13 sheets. Prior session left binaries but no sources; rewriting from scratch.
- A,D,F,G,K,M accepted (M needed __int128 for the DP window sum - 64-bit overflow).
- B,H,I written, stress-tested vs brute force + official samples, all accepted. 9 done.
- C accepted (interactive, 15/15). 10 done.
- E: hook-length refuted by brute force; derived rank-DP, verified 8000 random small cases
  vs permutation brute + 300 mid-size vs python DP + edge cases, accepted 101/101. 11 done.
- J: all 6 samples + 6000 random brute-force cases, accepted 34/34 max 630ms. 12 done.
- L: min-cost SIMPLE path on ring+Nook (negative edges => no Dijkstra). Arc costs collapse to
  +/-P[i] differences, so 9 island-island + 5 Nook candidate cases over range minA/minV/minPair.
  Two bugs found only by stress: (1) rangeAdd had no empty-range guard, so an a[n] update
  ([n+1,n]) pushed on a leaf and corrupted the tree; (2) a leftover placeholder read a stale
  prebuilt P[] after updates. Verified cpp == true DFS brute on 1200 update-interleaved streams,
  1800 vs direct formula, max-size 0.42s/60MB. Accepted 42/42 max 694ms. 13 done - ALL.

**L details**: valid route visits each of n+1 locations at most once => enumerate the 2 ring arcs
between s,t, and up to 2 flights via the Nook; each leg is a contiguous arc so its cost is
P[hi]-P[lo] (+/- T for a wrap). With A[i]=P[i]+b[i] and V[i]=b[i]-P[i] every case is a sum of
range minima over disjoint index ranges, and "arc s->i then arc j->t" is minPair(s,t) which the
segtree holds directly. a_x update = suffix [x+1,n] gets (A+=d, V-=d) + BIT point add; b_x update
= point (A+=d, V+=d). merge: minPair = min(L.pair, R.pair, L.minA + R.minV) (order matters).
