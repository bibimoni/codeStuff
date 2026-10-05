# Feedback — muse-spark-1.3

- A (suffix-array): medium | solved | forced-strict/optional-equal graph + longest path; proved -1 soundness, brute-validated construction on all perms n<=7.
- B (grid-reboot): medium | solved | one GF(2) Gauss-Jordan over closed-neighborhood matrix with all Q right-hand sides in bitsets.
- C (the-hidden-cave): medium | solved | interactive: left-descent height + binary search on last level, ~7063 queries worst case, verified with mock interactor.
- D (mulgame): easy | solved | classic multiply-by-9/2 threshold game.
- E (scheduling): medium-hard | solved | key insight: flex edges vanish (exactly one orientation per linear extension), then tree-poset LE via rank-distribution DP.
- F (snow-white): easy | solved | filter by the height occurring exactly seven times.
- G (self-crossing-turtle): easy-medium | solved | 3-case spiral-crossing formula, stress-checked against brute on 100k random cases.
- H (rlu-cache-easy): easy-medium | solved | Fenwick over timestamps for order statistics + ordered set for LRU eviction.
- I (coolant-loops): medium | solved | loops = E-V+C maintained under reverse-time DSU additions.
- J (dp-math-hard): medium | solved | zero-sum gives 2^cnt; else candidate targets from zero-dividing prefixes with ordered DP counting.
- K (zero-segment): easy-medium | solved | rake fills intervals free, so min endpoint pair a_i+a_j at distance>=k-1.
- L (coral-loop): hard | solved | wheel simple paths split into 4 hub cases served by doubled segtree (minX/minY/best-split) + Fenwick; caught degenerate-arc bug via stress.
- M (dp-counting-med): medium | solved | Mahonian DP with exact sliding window plus greedy k-th construction; first attempt failed on saturating-subtraction bug.

The judge was fast and reliable with clear verdicts, and encouraging early/often submissions caught my M overflow bug quickly. The problem set had a great difficulty spread with several problems collapsing under one key insight (E, K, J), which made triage very rewarding.
