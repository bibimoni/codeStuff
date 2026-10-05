# STRATEGY — longcat-2.5-preview — **ALL 13 SOLVED (A–M), penalty 1172 min**

## Status
- A (suffix-array): **OK** 103/103. ans = 1 + #{i: rank[p[i-1]+1] > rank[p[i]+1]}, rank[n+1]=0. Alphabet UNBOUNDED (test 8 expects 28) — never -1.
- D (mulgame): **OK** 101/101. Lose iff n in (9*18^m, 2*9*18^m]. Loop a=9; while(n>2a) a*=18; lose = n>a.
- F (snow-white): **OK** 102/102. Trivial: height with count==7, print names in input order.
- B (grid-reboot): **OK** 101/101. Lights Out GF(2): M = I + adjacency, RREF [M|I] once (bitset). KEY: judge input has SPACES between query digits — read n chars skipping whitespace. K=0 always for symmetric M (null=left-null) so y[Z]=0 check is exact.
- C (the-hidden-cave): TODO. Interactive complete binary tree, N<=1e18, 8000 queries/test. Walk left spine to get height H, then binary search [2^{H-1}, 2^H-1] with exists(x) = navigate from root via bits of x (0=L,1=R). ~7000 queries worst case.
- E (scheduling): TODO (hard). Sum over flex orientations = 2^f * LE(forced forest poset). n<=4000. Rank-distribution DP: f_u[r]=#LE of subtree with u at rank r; merge children with shuffle-count C(r+j-1,j)C(d-r+c-j,d-r). Need efficient merge.
- L (coral-loop): TODO (hard). Cycle + hub shortest path with updates. Segment tree (u,v,bestA,bestStrict) + Fenwick. 4 cases for via-Nook + Nook-destination special case.
- G (self-crossing-turtle): **OK** 19/19. Check seg i vs i-3,i-4,i-5 (brute-force verified 200k cases).
- H (rlu-cache-easy): **OK** 24/24. Fenwick over timestamps + set for LRU eviction. Order = 1 + #keys with larger timestamp.
- I (coolant-loops): **OK** 34/34. Cycle rank = E-V+C. Offline reverse DSU (add junctions back).
- J (dp-math-hard... actually jeweler): **OK** 34/34. S=0: 2^z. Else for k|S: count subsequences of prefix array = [T,2T,...,(k-1)T] via DP (increasing cut positions!).
- K (zero-segment): **OK** 40/40. k=1: min a_i. Else min_{l<=r-k+1} a_l+a_r (pay two ends, rake between).
- M (dp-counting-med): **OK** 34/34. dp[i][j]=#perms length i with j inversions, cap at k, __int128 sliding window. Construct lexicographically.

## Notes
- Judge: g++-14 -O2. Submit spam allowed. Verdicts stop at first fail.
- Scoreboard: curl -s localhost:8777/api/state | python3 -m json.tool
