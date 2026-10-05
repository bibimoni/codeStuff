# Feedback — longcat-2.5-preview (13/13 solved, penalty 1172 min)

- A (suffix-array): medium | solved | ans = 1 + #{i: rank[p[i-1]+1] > rank[p[i]+1]} (rank[n+1]=0); alphabet is UNBOUNDED (test expects 28), never -1.
- B (grid-reboot): medium | solved | Lights-Out GF(2): RREF of [M|I] via bitsets, M=I+adjacency. KEY GOTCHA: judge input has SPACES between query digits — read n chars skipping whitespace.
- C (the-hidden-cave): easy-medium | solved | Complete binary tree: walk left spine for height H, binary-search [2^(H-1), 2^H-1] with exists(x)=navigate from root via bits of x. ~7000 queries.
- D (mulgame): easy | solved | Lose iff n in (9*18^m, 2*9*18^m]; loop a=9, while(n>2a) a*=18, lose = n>a.
- E (scheduling): very-hard | solved | Answer = LE(forced forest poset) (flex orientation is DETERMINED by the permutation, so no 2^f factor). O(n^2) rank-distribution DP: f_u[r]=#LE of subtree with u at rank r; merge children with shuffle kernel C(r+k-1,k)C(d-r+c-k,c-k) and suffix/prefix W-sums by edge type.
- F (snow-white): easy | solved | Trivial: height with count 7, print names in input order.
- G (self-crossing-turtle): medium | solved | Spiral self-crossing: check segment i only vs i-3, i-4, i-5 (brute-force verified on 200k random + structured cases).
- H (rlu-cache-easy): medium | solved | LRU with order queries: Fenwick over timestamps + set for min-timestamp eviction; order = 1 + #keys with larger timestamp.
- I (coolant-loops): easy-medium | solved | #independent loops = cycle rank = E-V+C; process impacts offline in reverse with DSU (add junctions back, track E-V+C).
- J (dp-math-hard): medium | solved | S=0: 2^z (z=#zero proper prefixes). Else for each k|S: count SUBSEQUENCES of prefix array equal to [T,2T,...,(k-1)T] via DP (cuts must be at increasing positions — naive product formula overcounts!).
- K (zero-segment): easy-medium | solved | k=1: min a_i. Else min_{l<=r-k+1} a_l+a_r: pay two end mounds, rake (l,m,r) propagates zeros between them for free.
- L (coral-loop): hard | solved | Cycle+hub shortest simple path with updates. Segment tree (minU,minV,bestStrict) + Fenwick; decompose via-Nook into 7 cases (arc direction combinations), x<y strictness matters. Brute-force verified.
- M (dp-counting-med): medium | solved | k-th lex perm with m inversions: dp[i][j]=#perms length i, j inversions (cap at k, __int128 sliding window), then greedy construction.

## Experience
The judge was excellent — fast verdicts and the spam-submission policy let me iterate freely (e.g., B's spaced-input format and J's overcounting bug were both caught by cross-checking against brute force, then fixed and resubmitted). The problem set was well-balanced: 4 quick wins (A/D/F/K), 6 medium technique problems (B/G/H/I/J/M), and 3 genuinely hard ones (C/E/L) — E and L in particular needed careful derivation (forest-poset LE DP; segment-tree case decomposition) and both only fell after stress-testing against independent brute-force solvers. My main lesson: always cross-check nontrivial logic against a brute-force harness before submitting, since the judge's hidden tests are the only oracle and a single WA costs 20 minutes on solved problems.
