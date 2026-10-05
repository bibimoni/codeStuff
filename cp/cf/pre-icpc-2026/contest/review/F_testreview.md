# Test-Quality Review — F · 586329 · snow-white ("Finding the Seven")

Reviewer: read-only API audit. TL 2000 ms / ML 256 MB. Latest package (rev 11, id 1492102) READY **with verification**. Single-test input (no `t`), checker `std::lcmp.cpp` (answers are unique — the 7 names in input order — so a line comparator is correct here).

## Constraints (extracted from statement)

| Variable | Bound | Notes |
|---|---|---|
| n | 7 ≤ n ≤ 100 | men in park; **single test per file** (no multi-test, no sum bound) |
| \|S\| (name) | 1 ≤ \|S\| ≤ 10 | English letters only (a-z, A-Z) |
| H (height) | 1 ≤ H ≤ 1000 | integer |
| guarantee | exactly one height occurs exactly 7 times | "the seven dwarfs can be uniquely identified" |
| t / sum-over-tests | N/A | single-case format |

## Validator coverage gaps

`validator.cpp` (fetched via API) checks: n ∈ [7,100], name regex `[a-zA-Z]{1,10}`, H ∈ [1,1000], eof, and enforces **exactly one** height with count 7 (`ensuref(valid_dwarf_heights == 1)`). Full coverage of every stated bound + the uniqueness guarantee.
- Minor: `inf.strict = false` with plain `readInt/readToken` — per-line layout ("each of the next n **lines**") is not enforced (tab/multiple-men-per-line inputs pass). Harmless for correctness; cosmetic only.
- `problem.validatorTests` is **EMPTY** — no registered VALID/INVALID probe cases (missing probes: two heights ×7, zero heights ×7, n=6, n=101, H=0/1001, |S|=11, non-alpha name).

## Generation script

`gen.cpp` has a single parametric mode: `gen [n [salt]]` — n defaults to rng ∈ [7,100]; extra arg perturbs testlib's argv-hash seed. Generation: pick dwarf_height ~ U[1,1000], emit 7 dwarfs, then n−7 civilians with heights ~ U[1,1000] rejecting `h == dwarf_height` and `count[h] == 6` (caps civilian multiplicity ≤ 6 — preserves the guarantee), then full `shuffle`. Names are `rnd.next("[a-zA-Z]{1,10}")`.

Script = 100 generated tests (indices 3–102) after 2 manual samples: 3× n=7, 4× n=100, and 93 mid-size n ∈ [8,99]. No handcrafted modes beyond samples.

## Bound attainment (computed over ALL 102 test files, local dump `_judge/F/tests`, cross-checked 4 tests via API `problem.testInput`)

| Variable | Stated bound | Observed max/min across testset | Verdict |
|---|---|---|---|
| n min | 7 | 7 (5 tests: sample 2 + tests 3–5) | HIT |
| n max | 100 | 100 (tests 6,7,8,9) | HIT |
| H min | 1 | 1 (5 tests, incl. sample 1 where **dwarf height = 1**) | HIT |
| H max | 1000 | 1000 (tests 26, 72, 90 — civilian heights) | HIT |
| dwarf height extremes | 1..1000 | min 1, max 980 | PARTIAL — dwarf=1 covered (sample 1), dwarf=1000 **MISS** |
| \|S\| min / max | 1 / 10 | 1 and 10 (in every sampled n≥23 test) | HIT |
| civilian height multiplicity | up to 6 legal | max observed = 3 | MISS — no near-ambiguous (×4,5,6) test |
| guarantee check | exactly one ×7 | held in all 102 files (script-verified) | OK |

## Edge cases present

- n = 7 (all men are dwarfs, zero civilians): samples-level + tests 3–5 ✔
- n = 100 (max): tests 6–9 ✔
- dwarf height at extreme 1: sample 1 ✔ (also ensures nonzero/1-corner arithmetic)
- civilian heights at 1 and 1000: present ✔
- name lengths 1 and 10 hit in essentially every medium test ✔
- randomized dwarf positions (shuffle) in every test; answer order = input order, pinned by sample 1 (heights 1,2 with interleaved names would catch "sort by height/position in group" mistakes at statement level) ✔
- 102 tests on a trivial problem — random coverage is deep (n distribution spans 7–100).

## Edge cases MISSING (minor)

1. **dwarf height = 1000** (max dwarf-height 980). Symmetric corner to the covered dwarf=1.
2. **Civilian height(s) with multiplicity 4–6** — the statement allows other heights to repeat freely up to 6 times; gen caps at 6 but random collisions only reach 3. A test with, e.g., 6 men at height X plus 7 dwarfs at Y kills "first height with count ≥ K" or sloppy set-counting heuristics. This is the most tempting WA-adjacent trap for this problem.
3. All-same-civilian-height test (n=100 → 93 civilians all at one height).
4. Dwarfs pinned entirely at the head / tail of input (anti-positional shortcut). Low value given full shuffle coverage.
5. No validator tests registered (empty), no checker tests (acceptable — standard `lcmp`).
6. `problem.tags` is **EMPTY** — missing CF tags (would be `implementation, sortings` or `implementation, strings`).

## Anti-hardcode traps

Not really applicable: the answer is a set of 7 names determined by a global frequency property; there is no index-targeted optimum to pin. Random shuffle + 100 tests make input-shape hacks pointless. OK.

## TLE-killer analysis

N/A by design: n ≤ 100, \|S\| ≤ 10. Any correct O(n²) or even O(n³) brute runs in microseconds at n=100; no input can TLE an honest solution. There is no TL-tagged solution and none is needed — a "brute force" here *is* the intended complexity class. Sum-bound-saturation file: N/A (single-test format). Worst file (n=100) is ~1 KB of input. The testset cannot and does not need to kill TLE; verdict here is "not a flaw".

## Solutions roster

`solution.cpp` (MA), `7-dwarfs.cpp` (OK), `gemini.cpp` (OK). No WA/TL solutions — acceptable for a trivial A-level problem; MA correctness is cross-checked by two independent OK solutions and verify passed.

## VERDICT: PASS (with minor polish gaps)

Testset fully attains every stated bound, validator covers 100% of constraints + the uniqueness guarantee, package verified READY. Concrete (optional) additions:
1. One handcrafted test: dwarf height = 1000, n = 100.
2. One trap test: n = 13 with 7 dwarfs at height Y and 6 civilians all at height X (max legal ambiguity).
3. Register validator tests (VALID sample + INVALID probes: duplicate ×7 height, H=0, n=6).
4. Add tags (e.g. `implementation`).
