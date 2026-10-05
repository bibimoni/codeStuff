# Test review — I · 591900 · never-read-backwards ("Inside-Out Rules")

TL 1000 ms / ML 256 MB. 13 tests, all generated (none manual), 1 sample (test 1, `gen pledge`).
Method: statement from cached pre-audit; validator/checker/gen/solutions via `problem.viewFile/viewSolution`;
test contents reproduced **byte-identically (modulo CRLF)** by compiling gen.cpp and rerunning all 13
script lines (verified faithful against `problem.testInput` for tests 4, 9, 10, 13 — API output
truncates at 20000 chars, hence local regen; `_judge/I/tests` on disk is a STALE copy of a different
problem, not used).

## Constraints (extracted from statement)

| var | stated bound | meaning |
|---|---|---|
| t | 1 ≤ t ≤ 100 | test cases (multi-test input) |
| m | 1 ≤ m ≤ 100 | lines per test case |
| \|s\| | 1 ≤ \|s\| ≤ 10 000 | per-line length; lowercase Latin + spaces; no leading/trailing space |
| Σ\|s\| | ≤ 10^6 | total length over **all** test cases |

## Validator coverage gaps

validator.cpp checks: t∈[1,100] ✓, m∈[1,100] ✓, charset (a–z + space) ✓, no leading/trailing space ✓, EOF ✓, per-test setTestCase ✓. Two bound mismatches:

- **\|s\|: statement says ≤ 10⁴, validator enforces ≤ 2·10⁴** — and the generator's `max` mode emits 20000-char lines, so **official test 13 violates the published constraint**. Anyone trusting the statement (fixed `char buf[10001]`, `%10000s`-style reads, asserts) breaks on a valid-per-validator test. Real contest-fairness bug.
- **Σ: statement says ≤ 10⁶, validator enforces ≤ 2·10⁶** (and the `ensuref` message lies: `total %lld exceeds 1000000` while comparing against 2000000). Tests themselves stay ≤ 10⁶, so impact is latent, but the validator must match the statement.

## Bound attainment (all 13 regenerated tests measured, not eyeballed)

| variable | stated | observed max | where | verdict |
|---|---|---|---|---|
| t | ≤ 100 | 100 | tests 11, 12 (`manysmall`) | HIT |
| m | ≤ 100 | 100 | tests 9, 11, 12 | HIT |
| \|s\| | ≤ 10 000 | **20 000** | test 13 (50 lines × 20000) | **EXCEEDS STATEMENT** |
| Σ\|s\| | ≤ 10^6 | **1 000 000 exactly** | test 13 | HIT |
| min \|s\| | ≥ 1 | 1 | tests 2, 5, 6, 8, 11, 12 | HIT |
| m = 1 | min m | yes | test 2 (`1\n1\na`) | HIT |
| t = 1 | min t | yes | tests 1, 2, 9, 10, 13 | HIT |

Per-file totals: max file = test 13 (Σ=10⁶, 1 case). Biggest multi-test file: test 8 (t=30, Σ=134k); `manysmall` files = t=100 × m=100 × len≤20 (Σ≈105k).

## Edge cases present

- Minimal everything: test 2 = `t=1, m=1, s="a"`.
- Length-1 lines sprinkled through rand/manysmall (min len 1 observed in 5 files).
- Max nesting t=100 × m=100 (tests 11, 12).
- Saturating Σ=10⁶ with max-length lines (test 13).
- Palindrome lines (tests 3, 4 = reversal-invariant content; also mirrored-space placement).
- Lines with no spaces (test 2; random lines w/o spaces occur in rand modes).
- Lines with many spaces (every rndline plants spaces every 4–12 chars).
- CRLF reality check: Polygon stores tests with `\r\n`; sol_main (plain getline+reverse) passed full verification, so CRLF handling is consistent end-to-end (Polygon normalizes on run / testlib strips).
- Checker tests 1–2 (OK exact match / WA on line-order reversal) registered and passing.
- Validator test present (sample as VALID).

## Edge cases MISSING

- No test with m=100 AND long lines (only m=50 in the Σ-saturating test). Harmless — Σ bound caps it — but a `t=100`-style file with mixed mid-length lines near a per-test buffer assumption could add cheap insurance. Low priority.
- No INVALID validator tests registered (only a VALID one visible in cache): no k>n analogue, but add INVALID cases for bad char (uppercase/digit), leading/trailing space, \|s\| out of range, Σ violation, t=0. Nice-to-have, not blocking.
- Anti-hardcode traps: N/A for this problem type (answer is a pure function of the input; no index/stride heuristics exist).

## TLE-killer analysis

Problem is intrinsically O(Σ). Max input is 1 MB → sol_main runs in ~ms; there is **no natural super-linear idea to reject**, so the missing TL-tagged solution is defensible (roster is MA + OK + WA; WA = "reverse line order instead of line content", correctly rejected during verification — checker test 2 and the READY package with verify prove it). Test 13 (50 × 20000 chars) does kill the one quadratic trap (reverse by repeated string prepend, O(|s|²) ≈ 2·10¹⁰ ops over the file) — the Σ-saturating file doubles as the TLE guard. Honest brute force passing is not a defect here; it IS the intended solution.

## VERDICT: GAPS

Fix in this order:

1. **Statement/validator/test mismatch on \|s\| (blocking for contest use).** Tests contain 20000-char lines while the statement promises ≤ 10⁴. Pick one side: either change statement to "|s| ≤ 20 000" (one-word fix, keeps tests) **or** change `gen max` to 10000 and validator to ≤10000, resave script, rebuild. Do NOT ship with the current 2× mismatch.
2. **Validator Σ bound:** `ensuref(total <= 2000000)` → 1000000, and fix the lying error message.
3. (Minor) Add INVALID validator tests: bad char, leading/trailing space, length violation, Σ violation.
4. (Minor) Empty tutorial for an A-level problem is forgivable; consider 1-line "read whole lines / getline" hint — optional.

After (1)/(2): edit statement + validator, `problem.saveFile` validator if changed, rebuild package with verify=true, commit.
