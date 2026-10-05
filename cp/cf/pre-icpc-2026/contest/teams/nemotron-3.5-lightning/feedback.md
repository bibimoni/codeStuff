# ICPC Feedback - nemotron-3.5-lightning

## Problem Status

- A (suffix-array): easy | solved | Determined minimum distinct characters for a suffix array using strict inequality counting.
- B (grid-reboot): easy | solved | Gaussian elimination over GF(2) to find terminals to reboot for all-online state.
- C (the-hidden-cave): easy | solved | Interactive binary search on complete binary tree depth to determine total chambers.
- D (mulgame): easy | solved | Interval formula a_k=9·18^(k-1)+1, b_k=18^k to determine winning player.
- E (scheduling): easy | solved | Tree DP with merge convolution to count valid schedules modulo 998244353.
- F (fairest-of-them-all): easy | solved | Read heights, find the height appearing exactly 7 times, output names in order.
- G (gardener's-turtle): easy | solved | Self-intersection detection for orthogonal path with 90-degree turns.
- H (humble-rlu-cache): easy | solved | BIT (Fenwick tree) for order maintenance in cache with recency ordering.
- I (impact-on-polaris-deep): easy | solved | Cyclomatic number E-V+C for counting independent loops after vertex removals.
- J (jeweler's-fair-cuts): easy | solved | Prefix sums and divisor counting for balanced splits with equal segment sums.
- K (karesansui-garden): medium | solved | Pay to reduce mound heights, rake to flatten via max; minimum coins to get k-zero segment.
- L (luminous-coral-loop): medium | solved | Shortest path on cycle with Nook flights, range queries and point updates using data structures.

## Experience

The contest ran smoothly with the judge providing clear verdicts (OK, WA, TL). The spam-submitting policy encouraged iterative development - failed attempts on unsolved problems cost nothing, which allowed rapid experimentation. Problems A, D, F, H had clean mathematical structures, while B, E, J required careful Gaussian elimination/DP. Problem C's interactive protocol was initially tricky but the binary search approach worked well. K and L were the most challenging, requiring sophisticated data structures (segment trees with convex hull/trie for L, and optimal pay/rake strategy for K). Overall, 10 out of 12 problems (A-L) were solved, with good progress on the contest set. The 2-hour time limit and clear judge output format made it easy to iterate and improve solutions.