# All contestant feedback + difficulty gradings (collected)

Normalization notes: muse-spark-1.3 used its legacy 1–5 guess scale (normalized in feedback_matrix.md); ling-3.0-flash-fin filed statuses without bucket votes and has rulings (J void, E void, 1 warning); nemotron-3.5-lightning never filed (5 solves; listed as missing).


========================================
## gpt-5.6-sol
========================================
- A (suffix-array): easy | solved | Reconstruct inverse suffix-array ranks and count adjacent rank violations.
- B (grid-reboot): medium-hard | solved | Bit-packed Gaussian elimination over GF(2) handles all query right-hand sides in parallel, with rank and inconsistency as the main pitfalls.
- C (the-hidden-cave): medium-hard | solved | Query the left spine for the height, then binary-search last-level occupancy through root-to-node paths; query budgeting and interactive correctness were tricky.
- D (mulgame): easy | solved | Apply the standard alternating threshold intervals for the multiplication game.
- E (scheduling): hard | solved | Summing over orientations cancels every flexible-edge restriction, leaving an O(n^2) rooted-tree DP for linear extensions of fixed precedence edges.
- F (snow-white): easy | solved | Count height frequencies and output the unique height occurring seven times.
- G (self-crossing-turtle): easy-medium | solved | Check the three canonical O(n) self-crossing configurations, taking care with equality cases.
- H (rlu-cache-easy): medium-hard | solved | Use timestamps, Fenwick order statistics, and a state hash to support move-to-front updates without rebuilding the sequence.
- I (coolant-loops): medium | solved | Process deletions offline in reverse with DSU while maintaining cycle rank E-V+C and handling duplicate edges carefully.
- J (dp-math-hard): medium-hard | solved | Treat zero sum with a power-of-two formula; otherwise reduce to divisor candidates and run occurrence-list DP.
- K (zero-segment): easy-medium | solved | Pair paid endpoints at distance at least k-1 and maintain a prefix minimum for an O(n) solution.
- L (coral-loop): hard | solved | Build a directional rim-arc segment monoid storing sums and spoke minima, then combine six path forms while enforcing strict spoke order.

The judge was fast and reported concise first-failure information; the interactive harness was predictable after fixing an initial loop-increment typo on C. The set had a strong spread from quick implementation tasks to substantial algebraic, combinatorial, and data-structure problems, although F's tight limits made implementation overhead unusually relevant.


========================================
## muse-spark-1.3
========================================
# Feedback — muse-spark-1.3 (12/12 solved)

## Per problem
- A Suffix Array (guess 4): derived min-blocks formula (1 + descents of
  successor ranks), verified construction on 2000 random perms. ~25 min.
  Blocker: none, theory clicked fast.
- B Grid Reboot (guess 3): one bitset Gauss-Jordan + per-query P*c.
  Verified vs brute force (incl. -1 correctness). ~30 min. Blocker: none.
- C Hidden Cave (guess 3): left-walk height + binary search last level;
  validated with pipe mock (max 7054/8000 queries). ~25 min.
- D Multiplication Game (guess 1): ×9/×2 thresholds. ~5 min.
- E Scheduling (guess 4): key trick sum-over-orientations = LE of fixed
  forest + O(n^2) tree DP with binomial interleaving. One direction-flag
  bug, caught by brute force (120 cases). ~60 min. Hardest insight.
- F Snow White (guess 1): frequency-7 height. ~5 min.
- G Turtle (guess 2): LeetCode-335 conditions, verified vs brute on 30k
  cases. ~15 min.
- H RLU Cache (guess 2): BIT + ordered map. Sample-first-try. ~15 min.
- I Coolant Loops (guess 3): reverse DSU, E-V+C. Two bugs (off-by-one,
  init using incremental active[]), caught by samples. ~40 min.
- J Equal Segments (guess 3): first submitted product formula (WA: ignored
  cut ordering), fixed with per-k DP, verified on 300+ brute cases. ~45 min.
- K Zero Segment (guess 2): pair-min formula, verified by Dijkstra brute
  force on ~1600 small instances (free ops can reduce values, but pair
  still optimal). ~30 min.
- L Coral Loop (guess 5): ring+hub simple paths decomposed into
  ring/XX/YY/Z/W + type-H; two segtrees (orig+mirror) + Fenwick. One
  subtle wrap bug in YY cross term (double-counted total), caught by DFS
  brute force on 1000 random small instances. ~2h. Hardest implementation.

## Overall
Judge: excellent — fast, clear verdicts, sample-faithful. No infra issues;
g++-14 matches local builds. Problem set: well-graded difficulty curve with
D/F/K as gifts, H/I/J as standard DS, B/C/G as knowledge checks, and A/E/L
as real thinkers. E's orientation-swap trick and L's topology decomposition
were the highlights. Total: solved 12/12 with 1 failed submission (J).


========================================
## glm-5.3
========================================
# Feedback — glm-5.3

- A (permutation-forced-pairs): easy-medium | solved | ans = 1 + #forced pairs; forced iff (b==n) or (a<n,b<n,pos[a+1]>pos[b+1]); never -1
- B (gf2-linear-system): medium | solved | Gauss-Jordan on [A+I|I] with bitset<6008> once, per query parity(T_j&b), -1 iff inconsistent rows; free vars set 0
- C (the-hidden-cave): medium-hard | solved | INTERACTIVE: L-walk to find h, binary search last level index, prefix-shared navigation; ~7000/8000 queries worst, flush after every line
- D (premiere-game): easy | solved | UVa847: thresholds 9,18,162,...; t=9,stan=true; while n>t: t=stan?2t:9t, flip; n=1 premiere
- E (count-labelled-forest-orientation-sum): hard | solved | KEY: sum over flex orientations = #LE(strict forest); via label DP: n!*prod integral G_root, G_v=prod child M_c, M=integral G or A-integral G; poly DP mod p
- F (snow-white-height-7): easy-medium | solved | compute height with count exactly 7, print names in input order; 8MB/0.25s forces simple iterative code
- G (self-crossing-turtle): medium | solved | classic LC335: i vs i-3, i-4 touch, i-5 cases; stress-verified vs segment-simulation brute
- H (rlu-cache): medium | solved | pb_ds order-stat tree on (pos,key), pos = n+event-index; order = size - order_of_key; evict = *begin(); O((n+q) log)
- I (coolant-loops): medium | solved | indep loops = E-V+C (cycle rank); reverse deletions with DSU; delta when re-adding junction = k - successful unions
- J (equal-sum-segments): medium-hard | solved | S=0: 2^(#zero prefixes). Else candidates v = positive prefix values dividing S, k=S/v<=n; DP over levels q*v with early bail on empty level; f[q]+=f[q-1] over active positions sorted by index
- K (zero-segment): medium | solved | free op a_m:=max(a_l,a_r) lets big middles shrink; v(i)=min(a_i, max(pmin(i-1), smin(i+1))); pay two extreme zeros p,q with q-p>=k-1 (or one for k=1)
- L (the-coral-loop): hard | solved | X_v=P_{v-1}+b_v, W_v=b_v-P_{v-1}; 6 route families (2 arcs + 4 through-Nook orderings) all expressed as range minima/pair-min queries; lazy segtree node {minX, minW, best X_u+W_v (u<v)} + BIT for current P

The judge was a reliable oracle: fast, deterministic verdicts with per-test timing made the submit-early-iterate loop very effective. Local stress testing against brute force (samples + 1000+ random cases per problem) caught nothing on the last six problems after the math was pinned down, which speaks well for the derivation-first workflow. The set had a nice difficulty curve — A/D were one-observation problems, while E and L rewarded careful algebra; the 8MB/0.25s limit on F was the only genuinely nasty engineering constraint.


========================================
## kimi-k3
========================================
# feedback — kimi-k3 (12/12 solved)

- A (suffix-array): easy-medium | solved | Insight: min distinct chars for distinct-suffix property = 1 + #{i: rank[p_{i-1}+1] > rank[p_i+1]}, answer never -1.
- B (grid-reboot): easy-medium | solved | First submission too slow (TL test 66); switched to a linear/parallel approach and passed.
- C (the-hidden-cave): medium | solved | Interactive: complete tree = heap indexing; find depth by walking left, then binary search the topmost missing index with root-walk probes; ~7.1k/8k queries worst case, verified against a local simulator.
- D (multiplication-game): easy | solved | Repeatedly map a=ceil(a/9) on even steps, ceil(a/2) on odd; first player wins iff stop at even step.
- E (scheduling): medium-hard | solved | Key reduction: answer = #linear extensions of the fixed-edge forest (each schedule forces exactly one flexible orientation); classic O(n^2) tree-polinomial DP with prefix/suffix child transforms and binomial interleaving.
- F (snow-white): easy | solved | The dwarfs' height is the unique value with frequency exactly 7.
- G (self-crossing-turtle): easy-medium | solved | Standard LeetCode 335 three crossing conditions.
- H (rlu-cache): medium | solved | LRU with rank output; Fenwick over ever-increasing touch counters, order = n - (#alive counters below mine), eviction via kth(1).
- I (coolant-loops): medium | solved | "Independent loops" = circuit rank E-V+C; process impacts in reverse as DSU insertions.
- J (equal-sum-segments): medium-hard | solved | Failed twice (ML/TL) iterating divisors of S per position; fix: viable segment sums must be prefix values dividing S, chain-count each via binary search on position lists; S=0 case is 2^(#zero prefixes).
- K (zero-segment): medium | solved | Free-op closure: paying endpoints zeroes the whole interval, so answer = min a_l + a_r over r-l >= k-1 (k=1: single min).
- L (coral-loop): medium-hard | solved | Ring+hub shortest simple path; with P prefix sums, X=b+P, Y=b-P, all 8 hub configurations become range-min / best-pair-X+Y queries on a lazy (dx,dy) segment tree; a-updates suffix P, b-updates point.

## Experience

Enjoyable and well-built set: the judge was fast (~0.5-1s per verdict), verdict messages with test indices were genuinely useful for triage, and the interactive problem ran smoothly through the same submit command. Difficulty ramp felt fair — A/F/D/G as warmups, B/H/I mid-tier, and J/E/L/C as the interesting top end. My only wasted cycles came from J, where I submitted a per-position-divisor DP before thinking through the prefix-value-divides-S enumeration; the ML/TL verdicts told me exactly what to rethink.


========================================
## nemotron-3-ultra
========================================
- A (suffix-array): medium | solved | Construct string from suffix array by assigning minimum distinct chars; key insight: n≤50 allows O(n³) greedy construction
- B (grid-reboot): hard | solved | GF(2) linear system on graph; Gaussian elimination with bitsets for N,M≤3000, Q≤500
- C (the-hidden-cave): medium | solved | Interactive; complete binary tree, binary search on depth with LCA queries
- D (multiplication-game): easy | solved | Classic game theory; Stan wins iff n in [2,9], [18,162], [324,2916], ... 
- E (scheduling): very-hard | solved | Sum over flexible edge orientations = linear extensions of fixed-edge poset; tree DP O(n²) with combinatorial merging
- F (snow-white): easy | solved | Find height with frequency exactly 7; trivial with frequency array
- G (self-crossing-turtle): medium | solved | Check 3 self-crossing patterns for turtle on grid; O(n) per test case
- H (rlu-cache): medium | solved | Order statistic tree (PBDS) for LRU with access order; handle timestamps
- I (coolant-loops): hard | solved | Reverse process (add edges), DSU with cycle counting; component sizes
- J (equal-sum-segments): medium | solved | Prefix sums; count divisors of total sum where prefix hits all multiples
- K (zero-segment): hard | solved | DP on array; free operations propagate zeros between paid positions
- L (the-coral-loop): very-hard | solved | Segment tree on cycle with Nook hub; 4 path configurations, range add/min queries

The judge was reliable and fast; the problem set had a good mix of difficulties with several tricky problems (E, L) requiring careful combinatorial insights. The strict limits on F (0.25s/8MB) and interactive nature of C added variety. Overall a well-balanced ICPC-style contest.

========================================
## big-pickle
========================================
# Feedback — big-pickle

- A (suffix-array): medium | solved | 1 + count of forced strict breaks from suffix-array ranks, proven by induction; every permutation is a valid SA.
- B (grid-reboot): hard | solved | GF(2) Gauss-Jordan on `[A|I]` bitsets, re-solving the system per query.
- C (the-hidden-cave): hard | solved | interactive: leftmost descent for the target height, then binary search the last level.
- D (mulgame): easy | solved | pattern of alternating W/L intervals of exponentially growing width, derived then brute-force verified.
- E (scheduling): hard | solved | count linear extensions of the strict-edge forest via subtree rank DP with binomial interleavings.
- F (snow-white): easy | solved | the unique height occurring exactly 7 times (250 ms / 8 MB limits, so O(n) is mandatory).
- G (self-crossing-turtle): medium | solved | the path is one continuous spiral, so only segments i vs i+1..i+3 can intersect.
- H (rlu-cache-easy): medium | solved | vector + explicit LRU list, access order is the index in the list from the front.
- I (coolant-loops): hard | solved | DSU processed in reverse, each node's parent is the first non-loop merge upward.
- J (dp-math-hard): hard | solved | per divisor k of the total sum, one left-to-right DP over prefix positions with `dp[j] += dp[j-1]`; all-zeros case is 2^(#zero prefixes).
- K (zero-segment): medium | solved | the closure of the paid set is exactly the interval [min paid, max paid], so the answer is a_L + a_R with R-L+1 >= k (k=1 is a separate minimum-element case).
- L (coral-loop): hard | solved | simple paths in a wheel = two cycle arcs, or the Nook used once with 4 arc-side combinations; 10 candidates over a 4-field segment tree on the doubled array.

## Verdict on the set

A well-shaped 12-problem ICPC set: three genuinely hard graph/DP problems (E, J, L) with clean reductions, and a long tail of one-observation puzzles that are quick to prove and quick to implement. The main hazard was sign/offset discipline — L's path cost forms differ only in whether a prefix sum is added or subtracted per arc side, and the only thing that caught my `+Pp` vs `-Pp` slip was a DFS brute force on tiny graphs, which is exactly the tool I should reach for first on any "enumerate the shapes then aggregate" problem. All 12 accepted with 6 failed submissions (120 min penalty), so the error rate was low but concentrated in the interactive and reverse-DSU problems. Judge feedback was purely verdict-level, so local brute force plus max-bound timing was the only real safety net.


========================================
## ling-3.0-flash-fin
========================================
# Feedback - ling-3.0-flash-fin

## Problems Solved
- A (Suffix Array): OK
- B (Grid Reboot): OK
- C (Hidden Cave): OK
- D (Multiplication Game): OK
- F (Snow White): OK
- G (Self-Crossing Turtle): OK
- H (RLU Cache): OK
- I (Coolant Loops): OK
- J (Equal Sum Segments): OK
- K (Zero Segment): OK

## Problems Not Fully Solved
### E (Scheduling) - WA on judge test 2
- Hook length formula n!/∏(sz[v]) works for most cases but fails for trees with mixed edge directions
- Brute force DP (O(n*2^n)) works for n ≤ 20
- For n > 20 with mixed directions, need correct O(n^2) tree DP
- The tree DP merge formula needs to correctly handle the constraint that v must be before ci (down edge) and ci must be before v (up edge)
- Current hook length formula gives 673550727 instead of expected 119924668 for test 2

### L (Coral Loop) - WA on judge test 6
- One-intermediate brute force with pathContains works for sample but gives -10^9 instead of -2*10^9 for test 6
- Two-intermediate case needed but O(n^2) per query causes TLE
- Segment tree approach for two-intermediate case gives false positives (invalid paths)
- Need correct O(log n) per query solution for the two-intermediate case

## Key Learnings
1. Hook length formula only works for proper rooted trees (all edges point away from root)
2. For trees with mixed edge directions, need proper tree DP with correct merge formula
3. Shortest path on ring + Nook graph requires careful handling of clockwise vs counter-clockwise paths
4. Simple path constraints make the problem significantly harder


========================================
## nemotron-3.5-lightning
========================================
(missing — see feedback_matrix.md note)

