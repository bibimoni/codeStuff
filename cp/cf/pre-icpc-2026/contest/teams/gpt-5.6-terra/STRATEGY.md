# Contest Strategy

## Status
- A (archive-of-lost-letters): OK; scan adjacent suffixes and add a character only when their following-suffix ranks are reversed.
- B (blackout-on-the-neural-grid): OK; one GF(2) Gauss-Jordan elimination with all query right-hand sides appended.
- C (the-hidden-cave): OK; binary-search heap indices, probing each root-to-node path then returning to root.
- D (duel-of-the-twin-sisters): OK; winning threshold intervals alternate after multiplying the previous bound by 9 then by 2.
- E (engineer's-schedule): OK; flexible edges contribute one compatible orientation per permutation, then rank-distribution tree DP counts linear extensions of fixed directions.
- F (fairest-of-them-all): OK; count heights and print the unique group of seven in input order.
- G (gardener's-turtle): OK; three constant-space configurations characterize all crossings of a rotating orthogonal path.
- H (humble-rlu-cache): OK after rank off-by-one fix; order-statistics tree keyed by monotonic access time gives cache rank and LRU eviction in O(log n).
- I (impact-on-polaris-deep): OK; restore impacts in reverse with DSU, incrementing cycle rank only for an edge inside an existing component.
- J (jeweler's-fair-cuts): OK; for total zero choose any zero-prefix cuts; otherwise count chains through ordered occurrences of required prefix sums for each divisor segment count.
- K (karesansui-garden): OK; pay for two supports at distance at least k-1, then rake every interior mound to zero; k=1 is one payment.
- L (luminous-coral-loop): OK; doubled-cycle segment tree stores directional flight minima and ordered flight-pair minima under coordinate range shifts.
- M (marshal's-parade): OK; capped Mahonian DP, then greedily choose each available value using completion counts.

## Submitted
- F: OK (102/102).
- D: OK (101/101).
- H: WA (test 1; rank off-by-one), resubmitting.
- H: OK (24/24).
- M: OK (34/34; exhaustive reconstruction stress through n=7).
- J: OK (34/34; random brute-force stress).
- I: OK (34/34).
- K: OK (40/40).
- G: OK (19/19).
- A: OK (103/103).
- B: OK (101/101).
- C: OK (15/15).
- E: OK (101/101).
- L: OK (42/42).
