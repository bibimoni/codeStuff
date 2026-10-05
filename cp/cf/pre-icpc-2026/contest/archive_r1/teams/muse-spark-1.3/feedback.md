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
