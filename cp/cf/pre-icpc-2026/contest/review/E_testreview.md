# Test review — E 592142 honeycomb-census ("Ever-Growing Honeycomb")

TL = 1000 ms, ML = 256 MB. Packages: rev 8 built READY with verification.

## Constraints (extracted from statement)

- Multi-test input: first line `t`, then one `n` per line.
- `t`: `1 ≤ t ≤ 10^4`.
- `n`: `1 ≤ n ≤ 10^9` (one per test, no other parameters/arrays).
- No sum-over-tests bound (trivially bounded: at most 10^4 single ints).
- Output: one integer per test; note in statement says answer may exceed 2^32 (answer = 3n²−3n+1, max ≈ 3·10^18 → int64 required, 32-bit trap).

## Validator coverage gaps

validator.cpp: `t = readInt(1, 10000)`, each `n = readLong(1, 1·10^9)` + EOLN per line, trailing `readEof()`.

- t bound: CHECKED. n bound: CHECKED. Exact format (one int per line, strict EOLN): CHECKED.
- No declared bound is unchecked. No gaps.

gen.cpp modes: `sample`, `edge1` (t=1,n=1), `edgemax` (n=10^9), `trail` (5 near-max/prime-ish values), `full seed` (t=10^4, n∈[1,10]), `rand t lo hi seed` (clamps hi to 10^9 — correct).

## Bound attainment table

| variable | stated bound | observed max in fetched tests | HIT/MISS |
|---|---|---|---|
| t | 1 ≤ t ≤ 10^4 | 10000 (tests 10, 11, headers) | HIT |
| n (max) | 1 ≤ n ≤ 10^9 | 1000000000 (test 3 raw `1\n1000000000`; test 4 contains 1000000000) | HIT |
| n (min) | 1 | 1 (sample, test 2 raw `1\n1`, tests 10/11 min=1) | HIT |

Sampled tests: 2, 3, 4, 5, 8, 9, 10, 11 (raw inputs fetched, maxima computed programmatically; tests 10/11 results truncated by API at ~6450 lines but headers confirm t=10^4 and all fetched tokens in [1,10] matching `gen full`).

## Edge cases present

- n = 1 (minimum): test 2, sample.
- n = 10^9 (maximum, 64-bit overflow trap, answer 2999999997000000001 > 2^32): test 3, plus test 4 `trail` (1000000000, 999999999, 500000000, 999999937 (prime), 123456790).
- t = 1 and t = 10^4 extremes: tests 2/3 vs tests 10/11 (`full`, two seeds).
- Random coverage across magnitudes: test 5 (single n∈[1,10^9]), test 6 ([1,10^3]), test 7 ([1,10^5]), test 8 ([9·10^8, 10^9] high band), test 9 (t=1000, [1,10^9]).
- Checker verified with OK + WA (int32-flavored 0/6/18) checker tests; validator tests cover t=0, n=0, n=10^9+1 and the valid sample.

## Edge cases MISSING

None of substance. For a closed-form problem there is no useful "sorted/reverse/all-equal" dimension. Anti-hardcode index-sweep traps are not applicable (answer depends pointwise on n; nothing skippable).

## TLE-killer analysis

Honest brute = per-test loop summing ring sizes, O(n) work. Tests 3+4 already give ≈ (1 + ~4.1)·10^9 iterations of adds → ~5–15 s, ≥50x the 1 s TL. Tests 8+9 add more 10^8–10^9-scale n's. An O(n) brute cannot pass. There is no sum-bound quadratic scenario (no aggregate parameter). Observation: roster has MA/OK/WA only — no TL-tagged solution registered; the playbook roster suggests tagging the natural brute as TL, but given the testset provably rejects O(n) this is bookkeeping, not a test-quality hole.

## VERDICT: PASS

All statement bounds are validated, both extremes of both variables are present in actual tests, the int64 trap is explicitly targeted, and brute force is decisively TLE. No missing tests to add. (Optional niceties: a TL-tagged brute solution for regression-witness completeness; nothing blocking.)
