- A (suffix-array): easy | solved | Reconstruct inverse suffix-array ranks and count adjacent rank violations.
- B (grid-reboot): medium-hard | solved | Bit-packed Gaussian elimination over GF(2) handles all query right-hand sides in parallel, with rank and inconsistency as the main pitfalls.
- C (the-hidden-cave): medium-hard | solved | Query the left spine for the height, then binary-search last-level occupancy through root-to-node paths; query budgeting and interactive correctness were tricky.
- D (mulgame): easy | solved | Apply the standard alternating threshold intervals for the multiplication game.
- E (scheduling): hard | solved | Summing over orientations cancels every flexible-edge restriction, leaving an O(n^2) rooted-tree DP for linear extensions of fixed precedence edges.
- F (snow-white): easy | solved | Count height frequencies and output the unique height occurring seven times.
- G (self-crossing-turtle): easy-medium | solved | Check the three canonical O(n) self-crossing configurations, taking care with equality cases.
- H (rlu-cache-easy): medium-hard | solved | Use timestamps, Fenwick order statistics, and a state hash to support move-to-front updates without rebuilding the sequence.
- I (coolant-loops): medium | solved | Process deletions offline in reverse with DSU while maintaining cycle rank E-V+C and handling duplicate edges carefully.
- J (dp-math-hard): medium-hard | solved | Treat zero sum with a power-of-two formula; otherwise reduce to divisor candidates and run occurrence-list DP.
- K (zero-segment): easy-medium | solved | Pair paid endpoints at distance at least k-1 and maintain a prefix minimum for an O(n) solution.
- L (coral-loop): hard | solved | Build a directional rim-arc segment monoid storing sums and spoke minima, then combine six path forms while enforcing strict spoke order.

The judge was fast and reported concise first-failure information; the interactive harness was predictable after fixing an initial loop-increment typo on C. The set had a strong spread from quick implementation tasks to substantial algebraic, combinatorial, and data-structure problems, although F's tight limits made implementation overhead unusually relevant.
