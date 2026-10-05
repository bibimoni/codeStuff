# Test-quality review — C · 584556 · the-hidden-cave ("Count the Chambers")

Interactive. Hidden complete binary tree (heap-indexed, node 1 = root). Contestant walks with
`? L` / `? R` / `? B` (≤8000 queries per test case) and must print `! N`. Interactor is
non-adaptive (N list fixed in the input) and the tree is fully determined by N, so input
review == full test review. Package rev 9 READY with verification.

## Constraints (extracted from statement)

| Variable | Bound | Notes |
|---|---|---|
| T | 1 ≤ T ≤ 20 | multi-test, interactive |
| N | 1 ≤ N ≤ 10^18 | hidden; one per test case |
| queries | ≤ 8000 per test case | enforced by interactor (WA on excess) |

No sum-over-tests bound (not applicable — O(1) data per test).

## Validator coverage gaps

`validator.cpp` checks: T via `inf.readInt(1, 100, "T")`, each N via
`inf.readLong(1, 10^18)`, strict `readEoln` per line, `readEof`.

- **GAP (cosmetic): statement says T ≤ 20, validator accepts T ≤ 100.** Interactor also reads
  T in [1,100]. Validator test #2 confirms range [1,100]. No test uses T > 20, so nothing
  invalid is in the set, but the statement bound is not enforced. Tighten to `readInt(1, 20)`
  for consistency (or fix statement to 100).
- N bounds: fully enforced (1 and 10^18 both; validator test #3 rejects 10^18+1). ✓
- EOL/whitespace strictness: ✓.

## Generation script (testset "tests", 15 tests)

Tests 1–7 manual; 8–15 generated:

```
gen 20 1 1000000               > 8     # uniform small-mid
gen 20 1 1000000000000         > 9     # uniform ≤1e12
gen 20 1 1000000000000000000   > 10    # uniform full range
gen 20 5e17 1e18               > 11    # upper half-band
gen 20 99e16 1e18              > 12    # near-max band (last 1%)
gen_power 5                    > 13    # {31,32,33}
gen_power 56                   > 14
gen_power 59                   > 15
```

Manual tests: 1 = sample (T=1, N=6); 2–5 = exhaustive N = 1..80 (all four T=20);
6 = window around 2^58, 2^59 ±1, and 20 values clustered at 10^18 − {0,1,2,62,…,5.11e5},
including **N = 10^18 exactly**; 7 = 2^57/2^58 windows + 9e17..10^18−1 cluster.
`gen_power k` emits {2^k−1, 2^k, 2^k+1} clipped to range.

## Bound attainment table

Verified via `problem.testInput` on tests 9, 10, 13, 14, 15 (last 3 + mid 2) + full inline
manual tests from the API cache; computed with python (never eyeballed).

| Variable | Stated bound | Observed / where | Verdict |
|---|---|---|---|
| T max | 20 | 2–12 all have T=20 | HIT |
| T min | 1 | sample test 1 | HIT |
| N min | 1 | test 2 (N=1) | HIT |
| N max | 10^18 | test 6 (last case = 1000000000000000000) | HIT |
| N just below max | 10^18−1 … | tests 6, 7, 12 (max obs 999999999999999999) | HIT |
| Deepest tree (N ≥ 2^59, depth 60) | 2^59 = 576460752303423488 | tests 6, 15 (±1 window), 10 (max obs 999085076030549669) | HIT |
| Depth-boundary at 1e18 (< 2^60) | — | test 6/7 near-max cluster | HIT |
| Perfect trees 2^k−1 | — | 3, 7, 15, 31, 2^56−1, 2^57−1, 2^58−1, 2^59−1 | HIT |
| Single-left-child (N=2) | — | test 2 | HIT |
| 64-bit arithmetic trap region | — | 2^59 window (×2+1 ≈ 1.15e18 still < int64 max; interactor safe) | HIT |

Fetched-measurement details: t9 (1..1e12): min 4084182754, max 955415230293; t10 (full
range): min 7.4e15, max 999085076030549669; t13={31,32,33}; t14={2^56−1,2^56,2^56+1};
t15={2^59−1,2^59,2^59+1}. (One HTTP 429 on first fetch of t15; succeeded on retry.)

## Edge cases present

- N=1 (root only; L/R/B all return 0) ✓; N=2 (only left child) ✓; N=3 ✓.
- **Exhaustive small sweep N=1..80** (tests 2–5) — kills any small-N special-case or
  base-case bug and any index-targeted hack in the small band. Strong.
- Perfect trees 2^k−1 at small and near-max scales ✓.
- 2^k / 2^k±1 windows at k = 5, 56, 57, 58, 59 — i.e. the exact boundary where depth
  increments and where the last level has exactly one node ✓.
- N = upper bound exactly ✓; N clustered just below upper bound (5 files: 6, 7, 11, 12 + 10) ✓.
- Uniform random mid (1e6), upper-mid (1e12), full-range, upper-half, top-1% bands ✓
  (30/50/20 doctrine respected for a 2-variable interactive).

## Edge cases MISSING

- **2^k±1 windows for 6 < k < 56** (e.g. k ∈ {7, 8, 20, 30, 40, 50}): only k=5,56,57,58,59 are
  swept. A solution whose depth/binary-search logic is correct in general is extremely
  unlikely to fail only at mid k (random tests would catch it), but a cheap
  `gen_power 30` / `gen_power 40` would close the gap. LOW priority.
- T=20 with **all cases at N=1e18 exactly** (max-depth stress in one file): current near-max
  files are random bands; a fixated all-max file marginally stresses depth-60 handling
  deterministically. VERY LOW priority (test 6 already contains N=1e18 and depth-60 windows).

## Anti-hardcode analysis

Interactive with hidden N and exhaustive small sweep — memorization/hardcoding attacks are
structurally dead: N is never visible, answers must be derived per case, and N=1..80 exhaustively
swept removes any look-up-table shortcut there. Pinned-optimum sweeps don't apply to this I/O
shape. PASS.

## TLE / resource analysis

Time is trivial (O(1) data per case); the real budget is the **8000-query limit**, enforced by
the interactor with WA on excess. Standard solution: descend left to find depth (~60 queries),
then binary search the last level with walk-down/B-up probes (~60 × 60 ≈ 3600 queries) —
comfortably under 8000, confirmed by verified package. A naive counting-by-probing-node-existence
strategy needs Θ(N) queries → dead instantly on any large test (6, 7, 10–12, 14, 15: 10 files
with N up to huge). A per-level doubling search without binary search (Θ(depth²) ≥ 3600, still OK)
vs a quadratic-in-depth variant — still under 8000; the query cap mainly kills linear-in-N probes,
which the max tests do with enormous margin (N up to 10^18 vs 8000 = 10^14× over budget). No honest
brute force can pass. PASS.

## VERDICT: PASS

Testset is dense and well-shaped: exhaustive small sweep, power-boundary windows at the depth-transition
scales that matter, exact-max N hit, near-max clusters, and full-range randoms. 10 large-N files
decisively kill linear probing.

Suggested (optional) additions:
1. Add `gen_power` for a couple of mid exponents (e.g. `gen_power 30`, `gen_power 40`) to complete
   the 2^k±1 sweep across all depths 1..60.
2. Tighten validator (and interactor) T bound from 100 to the stated 20.
