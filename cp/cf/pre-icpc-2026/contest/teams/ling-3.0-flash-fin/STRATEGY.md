# Strategy - ling-3.0-flash-fin

## Contest Status
- Started at 23:44:37, 12s elapsed
- All problems unsolved
- 8 contestants, 13 problems (A-M)

## Problem Analysis

### A - Suffix Array (1s, 256MB)
Given a suffix array permutation, find min distinct chars. n ≤ 50.
Key insight: answer = 1 + count of positions i where p[i] < p[i+1] and rank[p[i]+1] > rank[p[i+1]+1], with special handling for p[i+1]=n.
Status: UNSOLVED - need to verify formula.

### B - Blackout on the Neural Grid (3s, 512MB)
Lights out puzzle on graph. Q scenarios. n ≤ 3000, M ≤ 3000, Q ≤ 500.
Gaussian elimination over GF(2). Medium-hard.

### C - Cave of Countless Chambers (2s, 256MB, INTERACTIVE)
Complete binary tree, find number of chambers. Interactive, 8000 queries.

### D - Duel of the Twin Sisters (1s, 256MB)
Game theory: multiply p by [2,9], first to reach ≥ n wins. O(log n) per test case.
Key: compute losing intervals from top. Trivial once formula is derived.

### E - Engineer's Schedule (2s, 256MB)
Count topological orders of a tree with flexible/strict edges. n ≤ 4000.

### F - Fairest of Them All (0.25s, 8MB) ← TIGHT!
Find 7 dwarfs with same height. n ≤ 100. Trivial implementation.

### G - Gardener's Turtle (2s, 256MB)
Self-intersection of spiral path. Classic computational geometry.

### H - Humble RLU Cache (2s, 256MB)
LRU cache implementation. Standard data structure.

### I - Impact on Polaris Deep (2s, 256MB)
Dynamic connectivity, count independent loops. Complex.

### J - Jeweler's Fair Cuts (2s, 256MB)
Count balanced splits of necklace. Medium.

### K - Karesansui Garden (2s, 256MB)
Greedy/DP for zeroing segments.

### L - Luminous Coral Loop (4s, 256MB)
Graph shortest path with updates. Complex.

### M - Marshal's Parade (2s, 256MB)
k-th permutation with exactly m inversions. Hard.

## Plan
1. Solve F (trivial, but tight 0.25s/8MB)
2. Solve D (game theory)
3. Solve G (spiral intersection)
4. Solve H (LRU cache)
5. Try more problems
