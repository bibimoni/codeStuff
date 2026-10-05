# Test-Quality Review — J "Just Split Evenly" (pid 584874)

Problem: count balanced contiguous splits (all strands equal sum), answer mod 1e9+7.
Intended: prefix-sum/divisor sweep, O(n·d) per test; key branches: total S=0 → 2^c;
signed prefix interleaving (order matters); 64-bit prefix sums up to 1e14.
Package state: READY, built with verification (tags asserted). Solutions: sol_main (MA),
sol_ok (OK), sol_tl (TL), sol_wa (WA), sol_hack_skip (WA anti-hardcode witness).

## Constraints (extracted from statement)

| Variable | Bound | Notes |
|---|---|---|
| t | 1 ≤ t ≤ 10^5 | multi-test input, t bounded |
| n | 1 ≤ n ≤ 10^5 | per test case |
| Σn | ≤ 10^5 | sum over all test cases |
| a_i | −10^9 ≤ a_i ≤ 10^9 | signed (debt stones) |
| answer | mod 10^9 + 7 | can be 2^(n−1) huge |
| implied |i|prefix sum | ≤ 10^14 | forces int64 (n·max|a|) |

## Validator coverage gaps

validator.cpp (testlib) checks: `t ∈ [1,100000]` (`readInt`), per-case `n ∈ [1,100000]`,
Σn ≤ 100000 incrementally (`ensuref` inside the loop), each `a_i ∈ [−10^9, 10^9]`
(`readLong`), strict one-space separation / EOLN per line, `readEof` at end.

**No gaps.** Every stated bound (t, n, Σn, a_i range, plus format/EOL strictness)
is enforced. Nothing in the statement is left unchecked.

## Generation script structure (34 tests, all generated, sample = test 1)

- Hardcoded modes: `sample1`, `tiny` (20 edge tests), `zeros` (S=0 shapes, answers 2^c),
  `eq` (all-equal, answers τ(n), n ∈ {2,3,60,360,5040,72072}, values ±1e9),
  `antitl` (n=98280 all-ones, ~4e10 ops for naive per-divisor sweeps),
  `divmax` (n=10^5, all 698377680 → S≈6.98·10^13 with 1721 divisors ≤ n; near the 10^14 int64 edge),
  `maxpairs` (n=10^5 alternating ±10^9 → S=0, c=49999, answer 2^49999 mod),
  `tmax` (t=10^5 of n=1, values cycling {0,±1,±10^9}).
- Anti-hardcode: `pinned 401` (16 tests, n=2·prime all-ones, q = nextPrime(547+283k) sweep →
  k=2 cut pinned exactly at moving index q), `pinnedone 49991/49993/49999` (n=99982/99986/99998).
- Sum saturation: `sumpack 501` (20 × n=5000 mixed patterns, Σn = 10^5 exactly),
  `rand 2 49998 50000 7 999999937 319` (Σn ≈ 10^5), tmax (Σn = 10^5).
- Medium rand spread: 17 `rand` files, patterns: uniform ±v, positive, zero-sum pairs,
  all-equal ±v, {−1,0,1}, cluster {0,1,2}, periodic (i mod 10), alternating ±v;
  n ranges 2..30 → 2000..5000 → 100000.
- Max-n singles: tests 28–30 `rand 1 100000 100000` patterns 0/1/3 with v=10^9, plus 27, 32.

## Bound attainment (fetched via problem.testInput; API truncates previews at 20000 chars — headers + leading content verified against gen modes)

| Variable | Stated bound | Observed max in fetched tests | Verdict |
|---|---|---|---|
| t (max) | 10^5 | test 34 (tmax): header t=100000, n=1 cases cycling {0,1,−1,10^9,−10^9} | HIT |
| t (min) | 1 | tests 27/31/32 all t=1 | HIT |
| n (max) | 10^5 | test 27 (maxpairs) n=100000; test 32 (divmax) n=100000; tests 28–30 per script | HIT |
| n (min) | 1 | sample, tiny, tmax | HIT |
| Σn | ≤ 10^5 | test 23 (sumpack): 20 × 5000 = 100000 exactly; test 34: 10^5 × 1 = 100000; test 33: 2 × ~50000 | HIT |
| a_i = +10^9 | 10^9 | tests 27, 34, 2 (tiny) | HIT |
| a_i = −10^9 | −10^9 | tests 27, 34, 2 (tiny) | HIT |
| max |prefix| ≈ 10^14 (int64 trap) | implied | test 32: S = 6.9837768·10^13 (all 698377680, n=10^5) | HIT (near-cap) |
| pinned sweep | anti-hardcode | test 18 (pinned): t=16, n=2·prime all-ones, q sweep confirmed 1094,1678,2246,2818,… | PRESENT |

## Edge cases present

- n=1 with values 0, +10^9, −10^9, generic (tiny ×4, sample, tmax ×10^5) ✓
- S=0 branch: zeros mode ×7 shapes (c=99, c=999, pairs, scattered zeros, ±10^9 bookends);
  maxpairs (c=49999 → 2^49999 mod, big-exponent stress); tiny cases ✓
- all-equal arrays with many divisors: eq (n=5040, 72072; values ±10^9, ±3, 7, 12345) ✓
- ordering trap (unordered count-product is wrong): tiny {-4,2,4,-3,-2} answer 1 vs
  product-says-2 — the named sol_wa idea ✓
- prefix-multiple-absent precheck: tiny {5,-5,5,-5,5} (S=5 but prefix 1 absent) ✓
- negative totals: {-2,-2,-2}, {-1,-1} ✓
- int64: divmax (S≈7·10^13), maxpairs intermediate prefix hits ±10^9 ✓
- highly composite n (τ/S stress): antitl n=98280 (τ=128, σ=403200), divmax (1721 divisors) ✓
- t=10^5 / per-test reset: tmax (n=1 ×10^5, all value kinds incl. 0 and ±10^9) ✓
- Σn saturated over medium n: sumpack (20×5000, five pattern classes) ✓
- anti-hardcode: pinned sweep (16 moving pinned cut indices) + pinnedone ×3 near n≈10^5,
  with sol_hack_skip registered as permanent WA witness ✓

## Edge cases MISSING

- No t-huge × n=2 file (e.g. t=50000, n=2) — tmax covers reset bugs at n=1 only; harmless
  (a stale array of size ≥2 across tests would still corrupt n=1 answers), but a 1-line add.
- No max-n test with values drawn from the open interval avoiding ±10^9 in a *random* pattern —
  moot: tests 28–30 use v=10^9 ranges, maxpairs uses exact ±10^9.
- Nothing else identified; reverse-sorted/sorted shapes are structurally irrelevant here
  (prefix-sum structure is what matters, and periodic/zero-sum-pair patterns cover it).

## TLE-killer analysis

- sol_tl is TL-tagged and the package was built **with verification**, i.e. Polygon itself
  ran sol_tl against this testset and observed a TL verdict. Empirical confirmation, not
  just intent.
- antitl (n=98280 all-ones): an honest "for each k | S, full sweep" or k²-scanning brute
  does ~10^9–4·10^10 ops — ≥50x budget vs the 10^7-op intended solution. ✓
- divmax: 1721 candidate divisors × naive sweep without precheck ≈ 1.7·10^8… borderline
  alone, but combined with antitl the naive-per-divisor shape dies. ✓
- Sum-saturating files for per-test quadratic solutions: sumpack (20×5000 → 5·10^8 for
  O(n²) per test), plus three n=10^5 singles (10^10 ops for O(n²)). ✓
- Honest brute force passing? No — verified TL tag says otherwise. PASS.

## VERDICT: **PASS**

Every declared bound is validated and attained; S=0/divisor/order branches each have
handcrafted traps; anti-hardcode sweeps with a registered hack witness; TL enforced both
by construction (antitl/divmax ≥50x) and empirically (verified package).
Optional one-liner improvement: a `t=50000, n=2` mixed-value file for per-test reset bugs.
