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
