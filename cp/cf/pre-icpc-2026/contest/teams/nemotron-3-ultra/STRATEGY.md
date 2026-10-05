# Contest Strategy - nemotron-3-ultra

## Problem Analysis & Triage

### Solved ✅
- **A - Archive of Lost Letters**: n ≤ 50. Suffix array → min distinct chars = #strict inequalities + 1. ✅
- **B - Blackout on Neural Grid**: GF(2) linear system. Gaussian elimination with bitsets on (I+Adj) matrix. Precompute RREF + transformation matrix P. Queries: b' = P*b, back-substitute. ✅
- **D - Duel of Twin Sisters**: Game theory, multiply by 2-9. Winning intervals: Stan (first) wins for n in (1,9] ∪ (18,162] ∪ (324,2916]... ✅
- **F - Fairest of Them All**: Find 7 men with same height. Trivial O(n). ✅
- **G - Gardener's Turtle**: Spiral path self-intersection. Check last 6 segments for intersection. O(n). ✅
- **H - Humble RLU Cache**: LRU with order queries. BIT + ordered set for positions. O((n+q) log n). ✅
- **I - Impact on Polaris Deep**: Grid pipes, independent loops = E - V + C. Offline reverse DSU adding junctions back. O((nm+q) α). ✅
- **J - Jeweler's Fair Cuts**: Count balanced splits. Prefix sums + DP for each segment sum X dividing total. O(n * divisors). ✅
- **K - Karesansui Garden**: Min cost for k zeros. Pay for two positions i,j with j-i ≥ k-1. Min a_i + a_j. O(n). ✅
- **M - Marshal's Parade**: k-th permutation with m inversions. DP counting + greedy reconstruction. O(n^2 + n*m). ✅

### In Progress / Attempted
- **E - Engineer's Schedule**: Tree DP for linear extensions of directed forest. Need to count permutations satisfying fixed edges. O(n^2) DP for tree poset. 🔄
- **L - Luminous Coral Loop**: Dynamic shortest path on cycle + hub. Segment tree with matrix/DP states. 🔄
- **C - Cave of Countless Chambers**: Interactive complete binary tree size. Binary search on levels with 8000 queries. 🔄

## Current Status
- A: ✅ OK (7 min)
- B: ✅ OK (41 min)
- C: ❌ untouched
- D: ✅ OK (4 min)
- E: 🔄 attempted, complex tree DP
- F: ✅ OK (3 min)
- G: ✅ OK (31 min)
- H: ✅ OK (33 min)
- I: ✅ OK (55 min)
- J: ✅ OK (20 min, 3 attempts)
- K: ✅ OK (11 min)
- L: ❌ untouched
- M: ✅ OK (21 min)

## Submission Order Plan (remaining if time)
11. E (tree DP, needs formula for merge)
12. L (segment tree, complex)
13. C (interactive, need to implement protocol)

## Notes
- Use g++-14 for local compiles
- Stress test with brute force before submitting
- Check scoreboard with curl localhost:8777/api/state
- Current: 10 solved, rank 9/12. Good progress!