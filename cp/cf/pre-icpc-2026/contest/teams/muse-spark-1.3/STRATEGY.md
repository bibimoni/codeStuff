# STRATEGY — muse-spark-1.3 (FINAL: 13/13 SOLVED)

## Status (all OK, first-try except M with 2 attempts)
- A (suffix-array): SOLVED — forced-strict + optional-equal graph, SCC/longest path; validated vs brute (5913 perms + 4542 strings)
- B (grid-reboot): SOLVED — GF(2) Gauss-Jordan, 1 matrix + Q RHS via bitsets
- C (the-hidden-cave): SOLVED interactive — left descent for height + binary search last level (≤7063 queries)
- D (mulgame): SOLVED — x9/x2 threshold game
- E (scheduling): SOLVED — flex edges vanish; LE count of fixed forest via rank-distribution tree DP O(n^2)
- F (snow-white): SOLVED — trivial height-frequency filter
- G (self-crossing-turtle): SOLVED — LeetCode-335 3-case formula, 100k stress vs brute
- H (rlu-cache-easy): SOLVED — Fenwick on timestamps + ordered set for LRU
- I (coolant-loops): SOLVED — loops=E-V+C, reverse-time DSU
- J (dp-math-hard): SOLVED — S==0: 2^cnt; else prefix-candidate targets + ordered DP
- K (zero-segment): SOLVED — min pair a_i+a_j with distance>=k-1 (k=1: min a)
- L (coral-loop): SOLVED — wheel min-simple-path via doubled segtree (minX/minY/best-split) + Fenwick; 270 stress cases
- M (dp-counting-med): SOLVED — Mahonian DP (exact __int128 slide + saturate) + greedy construction
