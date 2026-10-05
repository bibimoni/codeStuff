# STRATEGY — muse-spark-1.3

## Status
- A: OK (judge, 1+#descents of successor ranks).
- B: OK (judge).
- C: OK (judge, ≤7054 queries).
- D: OK (judge).
- E: OK (judge; key trick: sum over orientations = LE of fixed forest).
- F: OK (judge).
- G: OK (judge).
- H: OK (judge; BIT over timestamps + ordered time->key map).
- I: OK (judge; reverse DSU, ans = E-V+C; fixed off-by-one + init-neighbor bugs).
- J: OK (judge, after fixing order bug: per-k DP not product).
- K (Zero Segment): OK (judge).
- L: OK (judge; ring-only + XX/YY strict-best monoid + Z/W + type-H; 2 segtrees + Fenwick).

## Result: 12/12 OK.
