# glm-5.3 — contest feedback

- A (suffix-array): easy-medium | solved | Greedy min-alphabet classes via consecutive-SA pair strictness + naive SA verification to detect -1; brute-forced exhaustively n<=6.
- B (grid-reboot): medium | solved | GF(2) lights-out: RREF of [M|I] once with bitsets, per-query parity of L·b, x[pivot]=y, zero rows force -1.
- C (the-hidden-cave): medium | solved (interactive) | Probe left spine for depth d, then binary search last level by path bits; ~2d^2<=7200 queries/test, mock-interactor verified worst 7062/8000.
- D (mulgame): easy | solved | Win-interval ladder: b=9; while b<n multiply alternately by 2/9 flipping owner; French output strings verbatim.
- E (scheduling): medium-hard | solved | Key: flexible edges contribute exactly 1 orientation per permutation => answer = #linear extensions of forced forest only; tree-poset counting via cut-decomposition DP (L/R cumulative arrays + polynomial convolution, O(n^2)).
- F (snow-white): easy | solved | Find the height occurring exactly 7 times, print names in input order.
- G (self-crossing-turtle): medium | solved | HxH/VxV grouped interval-touch sweep + HxV sweep with multiset of active H, skipping at most 2 adjacent segment ids; adjacent pairs exempt.
- H (rlu-cache-easy): easy-medium | solved | Fenwick over LRU timestamp slots: rank = size - prefix(ts) + 1, evict via Fenwick descend; first version TL'd due to fixed mp.reserve per test (fix: proportional reserve).
- I (coolant-loops): easy-medium | solved | loops = E - V + C; offline reverse-order DSU insertions, cycle++ on same-root edge; brute-stressed hard after fixing double edge counting.
- J (dp-math-hard): medium | solved | S=0 -> 2^zero-prefixes; else k|S: DP over prefix positions ascending with stepTotal[i] (mod during accumulation — my first WA was an overflow there).
- K (zero-segment): easy-medium | solved | Insight: 2 paid anchors x<y at distance>=k-1 zero the whole [x..y] free via rake(x,m,y); answer = min a_x + suffix-min for k>=2, min element for k=1.
- L (coral-loop): medium-hard | solved | Exhaustive 4-shape decomposition of simple routes (front/front, back/back paired via a (mnA,mnB,pair)-merge segtree with range-add lazies; two cross shapes separable; hub destinations via 4 range-mins); Fenwick prefix sums for C constants; heavy brute stress n<=8 multigraph DFS.
- M (dp-counting-med): medium | solved | Mahonian DP with capped 2e18 sliding-window (u128), k-th lexicographic reconstruction choosing rank; first submission WA'd merely on a missing space in output.

The judge was an outstanding oracle: staged verdicts with test numbers made the TL (H reserve), WA (J overflow, M formatting) fixes each a 2-minute iteration, and the spam-friendly policy let me submit the moment a stress harness was green. Problem set had a lovely difficulty curve — F/K/D were 5-minute banks, while E and L rewarded a full combinatorial derivation; my only real time sinks were self-inflicted (M's output format, I's edge double-count). If anything, I regret the 20 minutes I spent re-deriving E's tree-poset DP after the answer was already reducible to "count linear extensions of forced edges".
