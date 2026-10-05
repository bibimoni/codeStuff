# Test-quality review — D 586686 "Duel by Multiplication" (mulgame)

API calls used: 11 (cache read, viewFile×3, script, testInput×7, one HTTP 429 on test 101 — analyzed via local reproduction instead).

## 1. Constraints (extracted from statement)

| Variable | Bound | Notes |
|---|---|---|
| T | 1 ≤ T ≤ 10⁴ | multi-test: T lines, one integer per line |
| n | 1 ≤ n ≤ 10⁹ | the only per-test data |
| output | one of two fixed French strings per test | checker: `std::lcmp.cpp` (case-insensitive line compare, ok) |
| TL/ML | 1000 ms / 256 MB | |

No sum-over-tests bound (per-test data is O(1), so fine). Answer structure: player to move **loses** iff n ∈ (9, 18] ∪ (729, 1458] ∪ (59049, 118098] ∪ (4782969, 9565938] ∪ (387420489, 774840978], i.e. (9^(2k-1), 2·9^(2k-1)]; first player wins everywhere else. The whole problem has ~6 answer classes + 10 exact boundary values + a 32-bit-overflow trap when simulating p (max p ≈ 9·10⁹ > 2³¹).

## 2. Validator coverage gaps

`validator.cpp` (testlib): reads T ∈ [1, 10⁴], then T ints n ∈ [1, 10⁹], then readEof(). **Every stated bound is enforced.** Gaps: (a) `skipWhitespace()` before/after tokens makes it liberal (accepts empty lines, junk whitespace) — cosmetic, not a hole; (b) `validatorTests` is empty — no VALID/INVALID validator regression tests registered; (c) `checkerTests` empty too.

## 3. Bound attainment (all 101 tests analyzed; gen reproduced byte-faithfully locally with testlib + seeds from script, verified verbatim against fetched tests 99/100)

| Variable | Stated bound | Observed in fetched tests | HIT/MISS |
|---|---|---|---|
| T max | 10⁴ | **9943** max over 100 files; min T=1023 | **MISS** (never 10⁴, never 1) |
| n min | 1 | **1440** | **MISS** — n=1–1439 never appear (except n=9,18,27 in the one sample) |
| n max | 10⁹ | 999,999,818 | **MISS** (close, not exact) |
| n = 1 | – | 0 occurrences | MISS |
| n = 9 / 18 / 27 | – | only in sample test 1 | partial |
| boundary values 9,18,729,1458,59049,118098,4782969,9565938,387420489,774840978 | – | **0 occurrences across 554,211 generated cases**; sample has only 9 and 18 | **MISS** |

Answer-class census over all 554,211 generated cases (exact): 2nd-player-wins intervals: (9,18]=**0**, (729,1458]=**1**, (59049,118098]=31, (4782969,9565938]=2540, (387420489,774840978]=214796. 1st-player intervals: n≤9=**0**, (18,729]=**0**, (1459,59049)=32, (118098,4782969)=2667, larger intervals well covered.

## 4. Script / generator analysis

Script = 101 tests: 1 manual sample (T=3: n=9,18,27) + 100 identical lines `gen <seed>` — the only generator mode is `rand`: T=rnd.next(1000,10000), then T values n=rnd.next(1,1e9). **No edge modes at all.** Uniform-in-[1,1e9] concentrates probability in the giant intervals; all small-n classes are statistically unreachable (observed: zero cases below n=1440). The single manual sample is doing all the edge-case work for the entire testset.

## 5. Edge cases present

- n=9 (first wins by one max move), n=18 (second wins, upper boundary of losing interval), n=27 — sample only.
- Large losing/winning intervals: solidly covered by volume; TLE-style volume (T≈10⁴ files) covered.

## 6. Edge cases MISSING

- **n=1** (degenerate: first player wins immediately), **n=10⁹** (max).
- **All 8 larger exact boundaries ±1**: 729, 1458, 59049, 118098, 4782969, 9565938, 387420489, 774840978 — any off-by-one in a boundary table (e.g. `<` vs `<=` at 729 or 1458) passes the full testset, since the only case in (729,1458] is 1 random non-boundary value and the interval (18,729] has no non-sample coverage at all.
- **n ∈ 2..8** (small first-player wins), **n ∈ 10..17** (second wins; sample has only n=18), n ∈ 19..729 (first wins; sample has only n=27).
- **T=10000 exact** (max-I/O stress; current max 9943 — near miss, minor) and **T=1** (degenerate single case).
- Anti-hardcode analog: no swept-boundary/boundary-saturated files, so table-hardcoding hacks with slightly shifted thresholds survive.
- Roster: only MA (`solution.cpp`, currently not retrievable via viewFile — 400 "Can't find source file", possible rename) + OK (`gemini.cpp`); **no TL and no WA solutions registered** (WA e.g. 32-bit-int simulator, or boundary off-by-one, would both currently be unverifiable).

## 7. TLE-killer analysis

Intended solution is O(1)/O(log n) per case; the natural brute force (simulate the game) is ≤ ~45 iterations per case and passes 10⁴ cases in ms — so an honest TL solution basically cannot exist; volume files (100×~5.5k cases) already stress I/O. Not a real gap for this problem, but the playbook's TL-tag requirement is unsatisfiable by construction; a WA-tag solution (int-overflow simulator or `<9`-style off-by-one) SHOULD be added to prove the tests kill it — currently nothing in the testset would catch a 9/18/729/1458 off-by-one except the sample for 9/18.

## 8. VERDICT: **GAPS**

Add (one file each, easy):

1. **Boundary sweep file**: handcraft T≈80 — n=1..40, plus each B ∈ {729, 1458, 59049, 118098, 4782969, 9565938, 387420489, 774840978} at B−1, B, B+1, plus n=10⁹−1 and 10⁹. This is the single test that makes the testset rigorous.
2. **T=1 minimal file** and **T=10000 file** (max I/O; generator never reaches 10³·∞ range endpoints — cap T at exactly 10000 in one file).
3. **n=1 and n=10⁹ explicit cases** (fold into #1).
4. Register a **WA-tag solution** (boundary off-by-one or `int` overflow) to lock in regression detection, since sample + randoms can't.
5. Optional: validator tests (VALID sample; INVALID t=0, n=0, n=10⁹+1) — currently zero registered.
