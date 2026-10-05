# Contest Strategy

- A (suffix-array): OK. Answer is 1 plus adjacent suffix-order pairs whose successor ranks are not increasing; empty suffix rank 0.
- B (grid-reboot): OK. Packed GF(2) forward elimination with all query RHS columns, then batched bitset back-substitution.
- C (the-hidden-cave): OK. Find left depth, then binary-search occupied nodes on last level by root-to-node walks; <7100 queries.
- D (mulgame): OK. Alternate threshold multipliers 9 and 2.
- E (scheduling): OK. Flexible orientations impose no net constraint when summed. Tree DP by root rank merges child orders with binomial interleavings in O(n^2).
- F (snow-white): OK. Count heights and print the unique group of seven in input order.
- G (self-crossing-turtle): OK. Standard three local crossing configurations in O(n).
- H (rlu-cache-easy): OK. Timestamp recency, Fenwick order statistics, set for eviction.
- I (coolant-loops): OK. Reverse deletions with DSU; cycle rank is E - V + components.
- J (dp-math-hard): OK. Zero total gives 2^(zero proper prefixes); otherwise candidate segment sums come from proper prefixes and DP advances through sorted occurrence lists of successive multiples.
- K (zero-segment): OK. k=1 minimum height; otherwise minimum endpoint sum with distance at least k-1.
- L (coral-loop): OK. Segment-tree arc aggregate stores sum, endpoint-to-spoke minima, endpoint-excluded minima, and best ordered spoke pair. Query combines the two s-t arcs and all valid center-route shapes.
- M (dp-counting-med): OK. Capped Mahonian DP and lexicographic unranking with Fenwick selection.

Final: all 13 problems A through M accepted; official history has one submission and one OK per problem.
