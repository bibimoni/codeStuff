# Test-quality review — K 581736 "zero-segment" (K-Long Zero Segment)

Reviewed: revision 14, latest package 1492103 READY "with verification". Read-only audit.
Method: cached pre-audit + `problem.viewFile` (validator.cpp, gen.cpp), `problem.script`,
`sol_tl.cpp` via viewSolution, `problem.testInput` for tests 22,25,31,35,36,38,39,40
(polygon_tool truncates at 20000 chars, so bound maxima computed over the full local
package tests in `_judge/K/tests`; remote-vs-local prefix match confirmed on tests
22/25/31/35/36/38/39/40 — identical modulo CRLF, local package is revision 14).

## Constraints (extracted from statement)

| Variable | Bound | Notes |
|---|---|---|
| t | 1 ≤ t ≤ 2·10⁵ | multi-test input |
| n | 1 ≤ n ≤ 2·10⁵ | per test |
| k | 1 ≤ k ≤ n | per test |
| aᵢ | 1 ≤ aᵢ ≤ 10⁹ | heights |
| Σn | ≤ 2·10⁵ | guaranteed over all tests |
| answer | up to 2·10⁹ | requires int64 |
| TL / ML | 2000 ms / 256 MB | |

## Validator coverage gaps

None. validator.cpp enforces: t ∈ [1, 2e5]; n ∈ [1, 2e5]; k ∈ [1, n] (read with
n as upper bound); each aᵢ ∈ [1, 1e9] with exact space/EOLN tokens; incremental
Σn ≤ 2e5 via ensuref; readEof at end. 7 validator tests registered (VALID sample,
k>n, a=0, a=1e9+1, t=0, bad EOLN, junk EOF) — all runVerdict match expected.

## Bound attainment table (all 40 generated tests, computed by parser)

| Variable | Stated bound | Observed max | Test file(s) | HIT/MISS |
|---|---|---|---|---|
| t | 2·10⁵ | 200000 | 35 (t=2e5, n=1,k=1 each, Σn=2e5) | HIT |
| n | 2·10⁵ | 200000 | 31-34, 38, 39, 40 (single-case max-n) | HIT |
| k | n (k=n) | 200000 | 34 (k=n=2e5) | HIT |
| k = 1 | 1 | 1 | 05, 18, 35 (whole files of k=1) | HIT |
| aᵢ | 10⁹ | 1000000000 | 15,16,17,24-30,34,37-40 | HIT |
| aᵢ = 1 | 1 | 1 | 09 (all ones), trap pins (26-30,38-40) | HIT |
| Σn | 2·10⁵ | 200000 | 28, 31-37, 38-40 (9 files at exactly 2e5) | HIT |
| answer (int64) | 2·10⁹ | 2e9 | 06 (alleq, k=5 → 2·1e9), 34 | HIT |

## Edge cases present

- n=1 (k=1): tiny file 03 (two n=1 cases: a=1e9 and a=1); keq1 (1,1,999999937).
- k=n: file 04 keqn (6 bespoke cases incl. both ends 1e9 → answer 2e9), test 34 k=n=2e5.
- k=1: file 05 keq1 (bare-min branch), file 18 (kMode 1 at n≤200), all of file 35.
- k=2 extreme width: test 40 = trap7, n=2e5, k=2, 1s pinned at both ends.
- All-equal: 06 (alleq 1e9 → int64 answer traps 2e9 / 1e9), 09 (all ones), 15/34 (pattern 3 all vmax).
- Sorted / reverse-sorted: 07 (mono, answers at both extremes), 13/32 (asc), 14/33 (desc).
- Value extremes 1 and 1e9 adjacent: pattern 4 (ends=1: 16, 37), pattern 5 (center pair=1: 17), pattern 6 (alternating 1/1e9: 22), farmin 08 (min walled / min pair centered).
- 64-bit overflow: 06 k=10 → 2e9; 34 → 2e9.
- min-behind-a-wall user regression case baked into file 03.
- Anti-hardcode pinned-unique-optimum sweeps: trap1 (central sweep, k∈{2,3,7,100,500} × offsets), trap2 (wide sweep step 31, k up to 769), trap4 (R sweeping near array END), trap5 (L sweeping near START, k∈{500,900}), trap6 (clustered minima, kills top-D value filters for D≤~620), trap3 × 2 (pinned optimum at R=100000 and R=150000 in n=2e5 singles), trap7 (end-pinned, kills arbitrary-width distance bands).
- Registered hack witnesses, all WA-tagged and linear so tags verify: sol_skip500 (index skip), sol_hack_band (distance band), sol_hack_stride (stride), sol_hack_topD (top-D). Package verify confirmed them wrong (earlier failure "sol_hack_stride got TL" was fixed in rev 6→7).

## Edge cases MISSING

- k = n−1 at max n specifically: only k∈{84254, 188865, 92555, 2e5, 50001, 75001, 2} at n=2e5;
  k=n−1 appears only at small n (mono file). kMode 3 exists (test 37: n=1e5, k∈[n−2..n]) —
  partially covered, just not at n=2e5. Cosmetic.
- Trap-3 pinned max singles only at R=1e5, 1.5e5 — an index-skip hack aimed at, say, the
  exact middle would also die on trap1/trap2 sweeps at smaller n only if it triggers there;
  acceptable coverage, could add one more pinned R (e.g. 30000) cheaply.
- Otherwise complete.

## TLE-killer analysis

sol_tl.cpp = honest O(Σ n·(n−k+1)) brute over all pairs. Worst file: any of 31-34/38-40
(single n=2e5) → ~2·10¹⁰ inner steps ≈ 40-80 s vs 2 s TL ⇒ ≥20-40x budget; package
verified tag TL on rev 14 (rev-6 failure fixed). Sum-saturating medium file 36
(200×n=1000, Σn=2e5) exercises per-test quadratic resets (~2·10⁸ ops — borderline,
but single-max tests are decisive). Main solution O(Σn) trivially inside TL.
t=2e5 file (35) kills per-test global-reset bugs. No honest brute force can pass.

## VERDICT: PASS

Every stated bound is validated and attained in real tests; edge/overflow/anti-hardcode
coverage is exemplary (7 trap variants + 4 registered hack witnesses, all verified by
build 1492103). No concrete missing tests. Optional polish only: a k=n−1 case at n=2e5
and one more trap-3 pinned R value.
