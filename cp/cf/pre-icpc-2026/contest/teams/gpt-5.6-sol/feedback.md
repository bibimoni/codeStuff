- A (suffix-array): easy-medium | solved | Compared adjacent suffixes through successor ranks; a new character is needed exactly when those ranks do not increase.
- B (grid-reboot): medium-hard | solved | Solved all scenarios together with packed GF(2) elimination and batched back-substitution.
- C (the-hidden-cave): medium | solved | Found the leftmost depth, then binary-searched the occupied prefix of the final level within the query budget.
- D (mulgame): easy | solved | Used the classic alternating threshold products by 9 and 2.
- E (scheduling): hard | solved | Observed that summing flexible orientations removes their constraints, then counted tree-poset linear extensions by root-rank DP.
- F (snow-white): easy | solved | Counted heights and printed the unique seven matching names in input order.
- G (self-crossing-turtle): medium | solved | Applied the three standard local self-crossing configurations in linear time.
- H (rlu-cache-easy): medium | solved | Maintained timestamp recency with a Fenwick tree for ranks and an ordered set for eviction.
- I (coolant-loops): medium | solved | Processed destruction offline in reverse with DSU while tracking the graph cycle rank.
- J (dp-math-hard): hard | solved | Used powers of two for zero total and sparse occurrence-list DP over successive segment-sum multiples otherwise.
- K (zero-segment): easy-medium | solved | Reduced a free-raked interval to two paid zero endpoints separated by at least k-1.
- L (coral-loop): very-hard | solved | Built a segment-tree monoid covering both cycle arcs and every valid simple route through the center under updates.

The judge was fast and especially useful for confirming the interactive protocol and tight-limit solutions. The set had a strong progression from direct observations to substantial algebraic, tree-DP, and dynamic-path problems; randomized brute checks paid off on the harder half.
