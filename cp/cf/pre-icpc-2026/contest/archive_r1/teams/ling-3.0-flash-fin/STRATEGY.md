# Strategy - ling-3.0-flash-fin

## Priority (by time-to-solution):
1. F (Snow White) - trivially easy, just filter
2. D (Multiplication Game) - game theory pattern
3. G (Self-Crossing Turtle) - known O(n) spiral check
4. H (RLU Cache) - straightforward implementation
5. A (Suffix Array) - analyze min alphabet
6. J (Equal Sum Segments) - prefix sums + counting
7. C (Hidden Cave) - interactive binary search on complete binary tree
8. K (Zero Segment) - greedy/DP
9. B (Grid Reboot) - GF(2) linear algebra
10. E (Scheduling) - hook length formula on forest of fixed edges
11. I (Coolant Loops) - cycle rank with reverse deletion + Union-Find
12. L (Coral Loop) - shortest path on ring + Nook with segment tree + lazy propagation

## Status:
- F: OK 102/102
- D: OK 101/101
- G: OK 19/19
- H: OK 24/24
- J: OK 34/34 (fixed WA with DP approach)
- K: OK 40/40 (greedy/DP)
- C: OK 15/15 (interactive binary search)
- B: OK 101/101 (GF(2) linear algebra)
- E: OK (hook length formula n!/prod(sz[v]), subtree sizes based on forest of fixed edges rooted at sinks)
- I: OK 2 1 0 0 / 1 0 / 0 0 / empty line (cycle rank = |E|-|V|+|C|, reverse deletion with Union-Find)
- L: OK (segment tree with lazy propagation for range add/range min, two trees val_A and val_B, Fenwick for prefix sums)

## Key learnings:
- E: hook length formula requires subtree sizes from forest of FIXED edges only, rooted at sinks (outdeg=0). DFS traverses undirected forest adjacency.
- I: cycle rank = |E| - |V| + |C|. Process deletions in reverse (additions). Union-Find maintains components. When adding node v with deg(v) edges connecting k components: Δcycle_rank = deg(v) - k.
- J: Counting approach failed for WA. Fixed by using DP handling ordering constraint.
- B: GF(2) linear algebra: precompute RREF + transformation matrix T.
- L: Ring + Nook graph. Shortest simple path has 5 cases: CW, CCW, direct Nook, Nook detour type 4, Nook detour type 5. Two segment trees (val_A = Q[i-1]+b[i], val_B = -Q[i-1]+b[i]) with lazy propagation for a_i updates, point updates for b_i changes.
