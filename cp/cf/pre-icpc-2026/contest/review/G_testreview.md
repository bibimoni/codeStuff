# Test-quality review — G 586335 "self-crossing-turtle" (Gardener's Turtle)

TL 2000 ms / ML 256 MB, 1 sample, 19 tests (all generated, none manual), checker.cpp (custom), validator.cpp. Package rev 24 built.

## Constraints (extracted from statement)

| Variable | Bound | Meaning |
|---|---|---|
| t | 1 ≤ t ≤ 10^4 | number of test cases (multi-test input) |
| n | 1 ≤ n ≤ 2·10^5 | moves per test case |
| Σn | ≤ 2·10^5 | sum of n over all test cases |
| d_i | 1 ≤ d_i ≤ 10^9 | punched-tape distances (positive integers) |

Output: `Yes`/`No` per test case, case-insensitive. No precision/mod/coordinate-range params (coordinates are derived, unbounded in statement but ≤ n·10^9, int64-safe).

Intended solution: O(n) with the 3-pattern local check (tutorial); brute force O(n²) must TLE.

## Validator coverage gaps

validator.cpp enforces: `t ∈ [1,10^4]`, `n ∈ [1,200000]` (`readInt` with bounds), running `Σn ≤ 200000` via `ensuref` per test case, `d_i ∈ [1,10^9]` via `readLong`, exact single-space separation with `readSpace`/`readEoln`, `readEof` at end.

**No gaps.** Every stated bound (t, n, Σn, d_i range, multi-test format) is checked.

Checker: custom word-wise compare with per-char `tolower` — matches the stated case-insensitive Yes/No; also enforces equal token count via `ouf.seekEof()` after answers are exhausted. Shape is correct.

## Bound attainment (API `problem.testInput` sampled; tool caps output at 20000 chars, so headers + leading values verified, tail relied on script construction — gen's `emit()` itself `ensuref`s Σn ≤ 200000)

| Variable | Stated bound | Observed max (fetched tests) | Verdict |
|---|---|---|---|
| t | 10^4 | 10000 (test 9 header `gen mix-tiny 10000 20 1000000000`) | HIT |
| n (single case) | 2·10^5 | 200000 (tests 12, 13, 16 headers; also 10, 11, 14, 15 by script) | HIT |
| Σn | 2·10^5 | exactly 200000 by construction in test 9 (10000×20) and in every single 200000 test; parsed 99 leading cases of test 9 all n=20 | HIT |
| d_i max | 10^9 | 1000000000 (test 12 = const 1e9 at n=200000, visible; test 5 rand with dMax=1e9) | HIT |
| d_i min | 1 | 1 (test 16 leading values; {1} and {1,1,...} in test 2 small) | HIT |

Sampled inputs written to /tmp/G_test_{9,12,13,16,17,18,19}.txt; per-case parsing across the fetched window: test 9 t=10000, n=20 each (max d 999391537 in window); tests 12/13/16 n=200000; tests 17–19 t=40, n=3000 each (Σn=120000, medium).

## Edge cases present

- n=1 ({1}), n=2, n=3 — minimal sizes (test 2 "small")
- Minimal crossing n=4: {2,1,1,2} (test 2)
- All three tutorial collision families at minimal size: lateCross1(10), lateCross2(10), lateCross3(12) (test 2)
- All-equal values: {1,1,1,1} (test 2); const 10^9 at n=200000 (test 12)
- Sorted (increasing) at max n: test 10 "inc"; reverse/decreasing at max n: test 11 "dec" — both are full-length "No" answers
- Extreme values: d=10^9 corners {1e9,1,1,1e9}, {1e9,1e9,1e9,1e9,1}, decreasing-from-1e9 (test 2); 32-bit overflow trap (d_i + d_{i-4} ≤ 2·10^9 > 2^31) covered by these
- Crossing pinned at the VERY LAST segment at n=200000, one test per collision family: tests 14/15/16 (latecross1/2/3 200000) — kills solutions that implement only a subset of the three patterns, and solutions that only detect early crossings
- Medium repeats of the same families: tests 17–19 (40× n=3000 each)
- t=MAX file: test 9, t=10000 with n=20 — per-test reset / I/O overhead
- Touch-only and overlap degenerates ("touching counts"): small-case family {5,1,5,1}, {1,1,2,1,1}, sample test 3 (segment 5 overlaps segment 1)
- Random mediums with varied dMax (5, 20, 3, 1e9): tests 3–6

## Edge cases MISSING

- None blocking. Two non-blocking observations:
  1. Anti-hardcode pinning is positional only at the *final* segment (and at min sizes). A hand-waved hack like "skip index k" isn't swept, but for this Yes/No problem the plausible wrong ideas are pattern-omission (all three families countered at min and max n) and all-pairs brute force (countered by tests 10/11), so the residual risk is minimal. Optional extra: a variant with the unique crossing mid-array followed by a non-crossing tail.
  2. t=MAX file uses n=20, not n∈{1..4}; a t=10^4 file of minimal-n cases would additionally stress verdict diversity/reset. Covered adequately in substance by test 9 + test 2.
- Verification limit: polygon_tool truncates `problem.testInput` at 20000 chars, so the *tail* of test 9 (cases 100–10000) was verified only by construction (header t=10000 + generator Σn assert), not by direct parse.

## TLE-killer analysis

- Brute force O(n²): worst single test is n=200000 → ≈2·10^10 segment-pair checks vs ~2·10^8 ops budget ⇒ ~100× over TL on tests 10 (inc, answer No — brute scans all pairs) and 11 (dec, answer No). Criterion "≥50× brute budget on a max test": **met**.
- Late-cross tests 14–16 (answer Yes only at segment n) also force the brute into ~n²/2 work under oldest-first inner loops; tests 10/11 are the guaranteed killers regardless of loop order (never-cross inputs).
- Σn-saturating file: test 9 (t=10000, Σn=200000) saturates the sum bound, though for this problem the single n=200000 tests are the quadratic kill; the sum file mainly guards per-test overhead/reset bugs.
- Honest O(n²) brute cannot pass: two independent full-length No-tests at max n. No TLE-quality FAIL.

## VERDICT: PASS

Every stated bound is validated (no validator gaps), every bound (t=10^4, n=2·10^5, Σn=2·10^5, d_i=10^9, d_i=1) is demonstrably hit by generated tests, the three collision families are pinned at both minimal and maximal n (test 2 + tests 14–16), full-length No-instances (inc/dec/const at 200000) kill O(n²) at ~100× TL, and the custom checker matches the case-insensitive spec. No mandatory additions. Optional: one mid-array-pinned unique-crossing test and one t=10^4 × n∈{1..4} file for extra paranoia.
