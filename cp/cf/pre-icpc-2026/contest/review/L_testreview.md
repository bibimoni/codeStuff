# Test-quality review — L 590582 "coral-loop" (Loop with a Lift)

Package: rev 10, READY "with verification" (solutions MA/OK/TL/WA all asserted). TL 4000 ms / ML 256 MB. Tags: data structures, graphs, shortest paths.

## Constraints (extracted from statement)

Multi-test input. Output = one integer per type-1 event.

| Variable | Bound | Notes |
|---|---|---|
| t | 1 ≤ t ≤ 3·10^5 | own bound stated |
| n | 2 ≤ n ≤ 3·10^5 | ring vertices |
| q | 1 ≤ q ≤ 3·10^5 | events per test |
| Σn | ≤ 3·10^5 | over all test cases |
| Σq | ≤ 3·10^5 | over all test cases |
| a_i, b_i | −10^9 ≤ · ≤ 10^9 | ring / spoke weights, may be negative |
| type-1 event | 1 ≤ s < t ≤ n+1 | t = n+1 is the central vertex |
| type-2/3 event | 1 ≤ x ≤ n, −10^9 ≤ w ≤ 10^9 | |
| answer | fits int64 only (up to ~3·10^5 · 10^9 ≈ 3·10^14) | implicit overflow trap |

Note: t's own upper bound 3·10^5 is unreachable — Σn ≥ 2t caps t at 150000. Statement is harmless but loose.

## Validator coverage gaps

validator.cpp checked against every stated bound:

- t ∈ [1, 3·10^5] ✔, n ∈ [2, 3·10^5] ✔, q ∈ [1, 3·10^5] ✔
- Σn ≤ 3·10^5 and Σq ≤ 3·10^5 enforced incrementally with `ensuref` ✔
- a_i, b_i, w via readLong ±10^9 ✔
- type ∈ [1,3] ✔; type-1: s,t ∈ [1, n+1] and s < t ✔; type-2/3: x ∈ [1,n] ✔
- Strict spaces/EOLN/readEof ✔, per-test `setTestCase` ✔

**No validator gaps found.** Every bound the statement declares is checked.

## Bound attainment table

Sampled inputs: tests 2, 4, 5, 6, 20, 31, 40, 41, 42 via `problem.testInput`. Large files come back truncated at ~20 000 bytes, but t/n/q headers are in the first bytes and parse cleanly; small tests parsed completely.

| Variable | Stated bound | Observed in fetched tests | Verdict |
|---|---|---|---|
| n max | 3·10^5 | test 5 (biganswer), 31, 40: `300000` in header | HIT |
| n min | 2 | tests 2, 42: n=2 | HIT |
| q max | 3·10^5 | tests 31, 40: `300000` in header | HIT |
| q min | 1 | test 2 (edgepack kind 0, 5th case, q=1) | HIT |
| Σn = 3·10^5 | max | test 41 (sumpack): 10 × 30000 = 300000 exactly | HIT |
| Σq = 3·10^5 | max | same test 41: 10 × 30000 | HIT |
| t max | 3·10^5 | test 42 (tmax): t = **99991** | partial — max achievable under Σn=Σq=3·10^5 with n=q=2 would be 150000 |
| a_i, b_i = 10^9 | max | tests 2/4 edgepack: `1000000000` (9×/23× occurrences) | HIT |
| a_i, b_i = −10^9 | min | test 6 spine, tests 2/4: `−1000000000` | HIT |
| update w = ±10^9 | max/min | edgepack kind 0 (`2 1 -1000000000`, `3 4 -1000000000`...), kind 2 | HIT |
| s=1, t=n+1 (full-span, center) | extreme | test 5: `1 1 300001` | HIT |
| x = n boundary update | extreme | test 5: `2 150000 …`; rand picks uniform 1..n at n=3·10^5 (x=1 and x=n occur w.p. ≈1 across 3·10^5 draws — verified x up to 300000 scale in gen, sampling confirms uniform) | HIT (probabilistic on max tests, exact on edgepack n=2: x=2) |
| 64-bit overflow trap | needed | test 5 biganswer: n=3·10^5 all a=−10^9, b=+10^9 → best route ≈ −3·10^14 | HIT |

## Edge cases present

- **n = 2 minimal** — edgepack kind 0/2, entire tmax file (99991 tests).
- **q = 1 minimal** — edgepack kind 0 case 5.
- **All-equal weights** — edgepack (a=b=5, and a=b=−1 blocks).
- **Monotone values** — maxmono (linear ramp ±10^9 over 3·10^5).
- **Alternating extremes** — maxmix (±10^9) plus clustered-minima spokes (kills "only pair among D smallest" filters).
- **Extreme values ±10^9, mixed signs, all-negative** — rand 300/1200/3000/8000 full-range, maxneg, biganswer.
- **Query to center (t = n+1)** — edgepack kind 1 (60% of events), maxhub (3·10^5 events, 90% `1 s n+1`).
- **No type-1 queries at all** — edgepack kind 0 case 6 (6 updates, 0 queries).
- **Update-heavy (95%)** — maxupd; query-heavy (5% updates) — maxquery; 50/50 — maxrand ×2.
- **64-bit overflow** — biganswer (~3·10^14 answers), full-range max tests.
- **Anti-hardcode traps** — `trap` mode: two pinned −10^9 spokes, ring zeros, unique mixed-orientation optimum −2·10^9; pin positions randomized per seed across 3 small (n=8/12/6), 3 medium (n=1000/3000/5000), 2 max (n=3·10^5, seeds 41/42). Gentle |w|≤3 updates preserve the trap. Registered WA solution (sol_wa.cpp, 4.7 KB linear-time) was rejected by verify.
- **t-max / minimal-tests stress** — tmax: 99991 tests of n=q=2.
- **Σ-saturation** — sumpack exactly saturates both sums at 10 × n=q=30000, alternating 20%/70% update mixes.

## Edge cases MISSING / weak

1. **t=99991 instead of 150000** — the tmax file stops at 2/3 of the truly maximal test count (n=q=2 per test ⇒ t_max=150000 under the sums). Per-test reset / O(t) allocation bugs get 66% of the achievable stress. Minor.
2. **Trap pin sweep is randomized, not systematic** — 8 trap files with random (k1, k2) per seed; an index-targeted single-point hack surviving is unlikely but not *provably* impossible (no deliberate sweep of mid-array indices at max n beyond the two 3·10^5 seeds). Acceptable; could add 1–2 trap files with pinned explicit k1/k2 near n/4, n/2, 3n/4.
3. **No max-size all-equal / trivial-answer max test** — maxmono and maxmix cover structured max inputs; a degenerate "all zeros at n=3·10^5, all queries" (constant answer 0) is absent. Cheap to add; only guards early-exit hacks.
4. **Statement t bound (3·10^5) inconsistent with sums** — cosmetic; no test can ever exceed t=150000.

## TLE-killer analysis

- Brute force (sol_tl.cpp): O(n) per event ⇒ O(n·q) = 3·10^5 · 3·10^5 = **9·10^10** operations on any of the ten n=q=3·10^5 files (maxrand×2, maxquery, maxupd, maxneg, maxmix, maxmono, maxhub, trap×2). That is ~4–5 orders of magnitude over a 4 s budget — far beyond the required 50× margin.
- Per-test quadratic total-work attacks (O(Σq · n) with medium n): sumpack (10 × n=30000, q=30000) forces 9·10^9 ops for any per-test quadratic — decisively dead.
- update-only/event-only degenerations cannot idle: maxupd (95% range-add point-update pressure) and maxquery/maxhub force ~3·10^5 queries each with n=3·10^5 spans.
- History shows the max tests are real teeth: rev 3 FAILED packaging because sol_main itself got TL on test 33 (maxquery); later fixed. Honest brute cannot pass. **TLE coverage: solid.**

## VERDICT: **PASS**

The testset hits every stated bound at max, saturates both sums exactly, covers the minimal/extreme/structured edge-case catalogue, carries genuine anti-hardcode traps plus a registered linear-time WA witness, and buries the brute force by 4+ orders of magnitude. Validator has zero coverage gaps.

Optional strengthening (none blocking):
1. `gen tmax`: emit 150000 tests (n=q=2) instead of 99991 to use the full achievable t.
2. Add 1 trap file with explicitly swept pin positions (k1,k2 at n/4, n/2, 3n/4) at large n.
3. Add one degenerate max test: n=3·10^5, all weights 0, all events type-1 — kills early-exit/assumption hacks.
4. Cosmetic: statement t bound 3·10^5 → 1.5·10^5 to match the sums.
