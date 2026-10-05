# Test-quality review — A / 585864 / suffix-array

**Problem:** Given a permutation p of 1..n (a candidate suffix array of an unknown string),
print the minimum number of distinct characters in any string whose suffix array is p, or −1.
TL 1000 ms, ML 256 MB. Single-test input (no t — appropriate for this problem).

## Constraints (extracted from statement)

| Variable | Bound | Notes |
|---|---|---|
| n | 1 ≤ n ≤ 50 | single test case per file (NOT multi-test) |
| p_i | 1 ≤ p_i ≤ n | guaranteed permutation of 1..n |
| t / sum-over-tests | — | absent by design |
| mod / precision | — | exact integer answer |

## Validator coverage gaps

validator.cpp (testlib) checks **everything the statement declares**:
- `n ∈ [1,50]` via `inf.readInt(1, 50)`.
- each `p_i ∈ [1,n]` via `inf.readInt(1, n)`.
- permutation property via distinctness set (n distinct values in [1,n] ⇒ permutation). ✓
- strict whitespace: exactly one space between tokens, EOLN after n and after p, `readEof()` (no trailing junk).

**No gaps.** (Minor style note: bound "permutation" is enforced as distinctness, which is equivalent here.)

Caveat: no `validatorTests` are registered on Polygon (empty), and no `checkerTests`
(checker is `std::lcmp.cpp`, fine for a unique integer answer). Registering 1 VALID +
2–3 INVALID cases (duplicate value, p_i > n, trailing space/blank line) is playbook step-13
hygiene; absence noted but low-risk since the validator is straightforward.

## Generation script analysis

100 generated tests (3-103) + 3 manual samples (1-3). gen.cpp modes:
- `n rand` — random permutation, pure `rnd.perm(n,1)`
- `n sorted` — identity (1,2,…,n)
- `n rev` — reverse (n,…,1) = suffix array of the all-equal string, forces answer 1
- `n string k` — suffix array of a random length-n string over k letters
  (k=1 ⇒ all-equal; k=26 ⇒ max source alphabet)

n=50 max tests in **all four structural patterns** (tests 8–11); n=1 in all four patterns (4–7);
n=2 present (test 98); k extremes present (k=1: tests 7, 87, 92; k=25–26: tests 11, 12, 76;
"k=6/3/2/1" small values scattered). Broad n sweep 1–50 across modes.

## Bound attainment (from fetched test inputs 1,2,3,4,8,11,50,75,101,102,103)

| Variable | Stated bound | Observed max/min | HIT/MISS |
|---|---|---|---|
| n (max) | 50 | 50 (tests 8, 11) | HIT |
| n (min) | 1 | 1 (test 4) | HIT |
| p_i (max) | n | 50 (tests 8, 11) | HIT |
| p_i (min) | 1 | 1 (many) | HIT |

All fetched files are structurally valid permutations (verified programmatically).

## Edge cases — present

- n = 1 (trivial, tests 4–7 in all modes) ✓
- n = 50 max, all four patterns (tests 8–11) ✓
- identity permutation `sorted` (forces answer 2 via the non-empty-tail rule) ✓
- reverse permutation `rev` = all-equal string ⇒ answer = 1 (minimum possible) ✓
- all-equal source string via `string 1` mode (tests 7, 87, 92) ✓
- max alphabet source `string 26` at n = 50 (test 11) ✓ — high-distinct-char answers
- random permutations across many mid n (10–49), high answer diversity ✓
- answer = −1 branch: **provably unreachable** — verified exhaustively locally for n ≤ 7 that
  every permutation is realizable (consistent with Duval's theorem); the −1 output is a hedge
  and cannot be tested. Not a gap.
- 64-bit overflow: N/A (answer ≤ 50).

Anti-hardcode sweep traps: not meaningful here — the answer is a global function of the
permutation; no index-skipping/strided heuristic survives 100 random tests. OK to omit.

## Edge cases — MISSING

None that matter for correctness. (Strictly: only 4 tests at n = 50; more would add nothing —
n = 50 is computationally trivial, so max-n is purely a format stress, which 4 files cover.)

## TLE-killer analysis

**N/A by design.** n ≤ 50 makes every honest polynomial algorithm instant; even is −1JV-style
try-all-alphabet-sizes O(n³·σ) verification runs in microseconds. A TL-tagged solution cannot
exist for these bounds (nothing ≤ 50-length can be made 50× over budget), so the MA+OK roster
(solution.cpp MA, gemini.cpp OK) is acceptable. Samples flagged (1–3). Latest package READY
"with verification standard" — verify passed and solution tags were confirmed.

Minor robustness misses (not correctness-critical):
- no WA-tagged tempting-wrong-idea solution registered (e.g., "answer = number of descents"
  without the rank[p+1] comparison, or greedy without the non-empty-tail rule);
- no validator/checker test records on Polygon (playbook step 13).

## VERDICT: **PASS**

Bounds fully enforced and attained, all meaningful edge classes covered, verify passed.
Optional polish (non-blocking): add 1–2 validator INVALID tests (duplicate p_i, p_i > n) and
one WA-tagged solution (descent-count heuristic) to lock the testset against regressions.
