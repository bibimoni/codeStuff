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