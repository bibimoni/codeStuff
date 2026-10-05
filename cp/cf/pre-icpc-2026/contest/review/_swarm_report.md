# Swarm Report: Per-problem test-quality review (13 Polygon problems)

**Mode:** swarm | **Tier:** auto | **Status:** completed

## Tasks

### ✓ coder: A 585864 suffix-array
- **Model:** my-local-server:kimi-k3 | **Duration:** 4m 29s | **Turns:** 14
- **Tokens:** ↑377k ↓9.3k | **Cost:** $0

  **Output:**

  ```
  Full script retrieved (100 generated tests). Now validator and gen:
  Validator and gen look good. Now sample actual test inputs (last 3 + a few mid + extremes):
  Rate-limited. Retry remaining with backoff:
  All checks done. Writing the review file:
  **A / 585864 / suffix-array — VERDICT: PASS**
  
  - Constraints: single-test input, n ∈ [1,50], p permutation of 1..n. Validator (testlib) enforces n, p_i range, distinctness, exact spaces/EOLN/EOF — **zero coverage gaps**.
  - Bounds all HIT: n=1 (test 4) and n=50 (tests 8, 11, verified by parsing fetched inputs); p_i=1..50 attained by permutation structure.
  - Script = 100 generated tests in 4 modes (rand/sorted/rev/string-k), max-n in all 4 patterns, k extremes (1 and 26) present, n sweep 1–50, samples 1–3 flagged.
  - Edge cases present: n=1, n=50, identity (ans=2), reverse/all-equal (ans=1), k=1/k=26. Answer −1 is provably unreachable (verified exhaustively n≤7 locally — every permutation is realizable), so it can't be tested; not a gap.
  - TLE: N/A by design (n≤50, TL 1000ms — no honest brute can be made slow; MA+OK roster fine, latest package READY with verification standard).
  - Minor non-blocking gaps: no INVALID validator tests registered, no checker tests (std::lcmp OK), no WA-tagged heuristic solution (e.g. naive descent-count) as regression witness.
  
  Full review: `contest/review/A_testreview.md`
  ```

### ✓ coder: B 585524 grid-reboot
- **Model:** my-local-server:kimi-k3 | **Duration:** 4m 47s | **Turns:** 19
- **Tokens:** ↑601k ↓14k | **Cost:** $0

  **Output:**

  ```
  Cache shows 101 tests, 1 manual sample, EMPTY validator/checker tests. Now fetch validator, gen, and full script:
  Key finding already: statement says scenario lines are "a string of N characters" (contiguous, e.g. `0101`), but validator reads N space-separated ints and the sample itself is `0 0 0 1 1 1 1` — a statement/test format mismatch. Also gen ignores its args (purely random per seed), never emits n=1 or m=0.
  
  Robust plan: regenerate all 100 tests locally (testlib rnd is deterministic per seed), verify byte-match against a few real Polygon tests, then compute exact stats. Check for testlib locally:
  Full local package exists at `_judge/B/` — all 101 tests + sources. No more API calls needed for inputs. Read checker + solutions (free, local):
  All stats computed locally over the full 101-test set. Cross-verify local files match Polygon's live data (1 API call):
  API testInput returned only 20001 bytes (test 101 is ~1MB — endpoint truncates large inputs). Verify prefix match instead:
  Prefix identical (tokens match; API truncates at ~20KB) → local stats are authoritative. One last structural pass (degree-0 vertices, connectivity, K=N-ish answers):
  All evidence in. Writing the review:
  Review written to `review/B_testreview.md`. Full 101-test set analyzed locally (mirrors Polygon; test 101 token-prefix verified against live API). 4 API calls used.
  
  **VERDICT: GAPS**
  
  1. **No stated bound is ever hit**: N max 2926 (not 3000), M max 2976 (not 3000), Q max 499 (not 500); min corners n=1, m=0, q=1 all ABSENT (gen ignores args, everything is per-seed uniform random — exact bounds never pinned). A `bitset<2950>`-style size hack passes all 101 tests.
  2. **Statement/data format mismatch**: statement says each scenario is "a string of N characters" (`0101…`) but validator/checker/gen/tests all use space-separated ints — getline/whole-line readers break on real data. Fix statement wording.
  3. **Checker hole**: "K distinct integers" not enforced — duplicate toggles accepted; 0 validator tests and 0 checker tests registered on Polygon.
  4. K=0 / all-zero / impossible coverage exists only by dice-roll luck (14/10 scenarios); nothing handcrafted.
  5. TLE side is healthy: 5 tests with n·q≈10⁶ kill per-query elimination ≥25× over; MA uses ~15–20% of TL.
  
  To add: one exact-max (3000,3000,500) file, n=1/m=0 and n=3000/m=0 (all-zeros → K=3000, max output) files, pinned K=0/K=n handcrafted file.
  ```

### ✓ coder: C 584556 the-hidden-cave
- **Model:** my-local-server:kimi-k3 | **Duration:** 2m 52s | **Turns:** 8
- **Tokens:** ↑238k ↓7.1k | **Cost:** $0

  **Output:**

  ```
  Cache loaded. Interactive problem, T≤20, N≤1e18. Now fetch validator, gen, and full script.
  Test 15 hit HTTP 429 — retry after pause, and compute per-file min/max.
  All data gathered. Writing the review.
  Review written to `review/C_testreview.md`. Summary:
  
  ```
  C 584556 the-hidden-cave — VERDICT: PASS
  Bounds: T≤20 HIT (tests 2-12), N=1 HIT (t2), N=10^18 exactly HIT (t6), N=10^18-1 cluster HIT (t6,7,12),
          deepest tree 2^59 HIT (t6,15). All stated bounds are attained in actual tests.
  Query budget: 8000/test enforced by interactor; intended O(log^2 N) walk ≈3.6k queries passes,
          linear probing needs Θ(N) → 10^14x over budget on 10 large files. No brute force passes.
  Strengths: exhaustive N=1..80 sweep (t2-5), 2^k±1 windows at k=5,56,57,58,59, exact-max N,
          near-max random bands (99-100%), uniform full-range randoms.
  Gap 1 (worst): validator/interactor allow T≤100 but statement says T≤20 — stated bound not enforced
          (cosmetic; no test exceeds 20).
  Gap 2: no 2^k±1 boundary tests for 6<k<56 — add `gen_power 30`/`gen_power 40`. Low priority.
  Gap 3: no all-cases-N=1e18 single file; test 6 already covers it per-case. Very low priority.
  API notes: ~10 calls total; one HTTP 429 on testInput 15, succeeded on retry. Nothing modified.
  ```
  ```

### ✓ coder: D 586686 mulgame
- **Model:** my-local-server:kimi-k3 | **Duration:** 3m 29s | **Turns:** 13
- **Tokens:** ↑396k ↓10k | **Cost:** $0

  **Output:**

  ```
  Parsed: **D, PID 586686, mulgame**. Cache read. Now fetching validator, generator, and full script.
  Validator and gen both straightforward. Now sampling test inputs (last 3 + 2 mid) and checking the MA solution.
  All files exactly 20001 bytes — suspicion of truncation. Checking tails and polygon_tool behavior.
  testlib.h exists. Compiling gen.cpp locally to reproduce the full testset exactly (no more API calls).
  Local gen reproduces test 99 exactly (T=2814 match). Verifying seed→test100 mapping, then analyzing the whole testset.
  Confirmed twice: local gen is byte-faithful. Now full testset analysis.
  All data gathered. Writing the review.
  Review written to `contest/review/D_testreview.md`.
  
  **VERDICT: GAPS** — D 586686 mulgame (T≤10⁴, n∈[1,10⁹]; answer = 6 interval classes with 10 exact boundaries).
  - Bounds never hit: **T=10⁴** (observed max 9943), **n=1** (observed min over 554,211 cases = **1440**), **n=10⁹** exact (max 999,999,818).
  - Testset is 100 identical-mode `gen <seed>` files (uniform n∈[1,1e9]) + one sample. Reproduced all gen tests byte-exactly locally (verified vs fetched tests 99/100): **zero cases with n≤18 outside the sample**, only 1 case in (729,1458], and **no exact boundary value** (729/1458/…/774840978±1) appears anywhere.
  - Worst gaps: (1) no boundary sweep → any off-by-one in interval tables (729/1458 and up) passes everything; (2) n=1/n=1e9/T=1/T=10⁴ degenerate & max-I/O files absent; (3) no WA/TL solutions registered, so the missing boundary kill-power is unprovable; validator does cover both stated bounds (minor: validatorTests/checkerTests empty; `solution.cpp` viewFile now returns 400 — possibly renamed since cache).
  - Fix: add one handcrafted ~80-case boundary file (n=1..40 + each boundary ±1 + 1e9−1, 1e9), a T=1 and a T=10000 file, and register a WA-tag boundary/overflow solution.
  ```

### ✓ coder: E 592142 honeycomb-census
- **Model:** my-local-server:kimi-k3 | **Duration:** 1m 39s | **Turns:** 10
- **Tokens:** ↑245k ↓4.3k | **Cost:** $0

  **Output:**

  ```
  Cache read. All bounds (t≤10⁴, n≤10⁹) are checked by the validator. Now sample actual test inputs to verify bound attainment.
  Tests 10/11 truncated by API at ~6450 lines but header says t=10000 — fine. Verify tests 2,3 then wrap up.
  All data gathered. Writing the review.
  VERDICT: PASS — review at contest/review/E_testreview.md
  - Problem: t≤10⁴, n≤10⁹, answer 3n²−3n+1 (statement flags >2³² answer as trap). Closed-form; only MA/OK/WA solutions.
  - Bounds hit: t=10000 (tests 10/11, `gen full`), n=10⁹ (test 3 `edgemax`, verified raw "1\n1000000000"), n=1 (test 2, sample).
  - Validator: enforces t∈[1,10⁴], each n∈[1,10⁹], strict EOLN/EOF. Zero coverage gaps; validator+checker tests registered and behaving as expected.
  - TLE: O(n) brute gets ~5·10⁹ iterations across tests 3+4 (+8,9) → ≥50× the 1s budget. Cannot pass.
  - Edge cases: min/max n, near-max primes (999999937), t extremes — all present. Anti-hardcode sweeps N/A for pointwise formula.
  - Worst gaps: (1) no TL-tagged brute registered — bookkeeping only, testset still rejects it; (2) API truncates large testInput fetches (~6450 lines on 10⁴-test files) — a fetch artifact, headers confirm full t.
  ```

### ✓ coder: F 586329 snow-white
- **Model:** my-local-server:kimi-k3 | **Duration:** 6m 12s | **Turns:** 15
- **Tokens:** ↑496k ↓9.4k | **Cost:** $0

  **Output:**

  ```
  Cached pre-audit read. Letter **F**, PID **586329**, name **snow-white** (statement title "Finding the Seven"). TL 2000 ms, ML 256 MB, single-test input, checker `std::lcmp.cpp`, latest package READY with verification. Now fetch validator/gen sources and the full script:
  The response format differs — let me inspect raw output:
  Rate limit persists — using 30 s spacing, one call per attempt:
  All guarantee checks hold. To avoid burning API calls on 102 tests, let me check the local tests dir referenced in the cache meta:
  n=7 tests have only the dwarf height — `max()` over empty others. Fixing:
  Everything verified. Writing the review:
  **F snow-white (586329) — VERDICT: PASS (minor gaps)**. Full review at `contest/review/F_testreview.md`.
  
  - Statement constraints: n∈[7,100] single-test, name|S|∈[1,10] α-only, H∈[1,1000], exactly-one-height-appearing-7× guarantee. Validator checks **every** bound + the guarantee; no holes (only cosmetic: per-line layout not enforced).
  - Bound attainment computed over **all 102 test files** (local `_judge/F/tests` dump) + 4 API spot-checks: n=7 (5 tests) ✔, n=100 (4 tests) ✔, H=1 ✔ (5 tests, dwarf-height=1 in sample 1), H=1000 ✔ (3 tests), |S|=1 & 10 ✔ in every medium test, guarantee holds in 102/102.
  - Never hit: **dwarf height = 1000** (max 980); **civilian height multiplicity 4–6** (gen allows up to 6, random collisions cap at 3) — the one trap worth adding.
  - TLE: N/A by design (n≤100 makes any honest brute instant); no TL/WA roster — acceptable for a trivial problem; package rev 11 READY with verification, MA cross-checked by 2 OK solutions.
  - Hygiene gaps: `validatorTests` empty, `checkerTests` empty, **tags empty** — add `implementation`.
  - Concrete additions suggested: dwarf=1000 handcrafted n=100 test; n=13 trap with 6 civilians sharing one height; INVALID validator probes (two ×7 heights, H=0, n=6).
  ```

### ✓ coder: G 586335 self-crossing-turtle
- **Model:** my-local-server:kimi-k3 | **Duration:** 7m 51s | **Turns:** 12
- **Tokens:** ↑330k ↓7.6k | **Cost:** $0

  **Output:**

  ```
  Validator and gen look solid. Now let me fetch the checker (Yes/No case-insensitive answers need a custom checker) and sample actual test inputs to verify bound attainment.
  All data gathered. Writing the review.
  Review written to `contest/review/G_testreview.md`.
  
  **VERDICT: PASS** — G 586335 self-crossing-turtle (19 tests, rev 24).
  
  - Validator: full coverage, no gaps (t≤10⁴, n≤2·10⁵, Σn≤2·10⁵ running check, 1≤d_i≤10⁹ via readLong, strict EOL/EOF).
  - All bounds HIT in fetched inputs: t=10000 (test 9 header), n=200000 (tests 12/13/16), d=10⁹ (test 12 const@200000), d=1, Σn=200000 exact (test 9: 10000×20, gen's emit asserts it).
  - Edge cases: n=1..3, minimal n=4 crossing, all 3 collision families at min AND max n (tests 2, 14–16), inc/dec/const at 200000, 1e9 corners incl. int32-overflow traps (d_i+d_{i-4}≤2·10⁹), touch/overlap degenerates.
  - TLE: tests 10/11 (inc/dec, full-length "No", never early-exit) force O(n²) brute to ~2·10¹⁰ ops ≈ 100× TL — brute decisively dead; test 9 saturates Σn.
  - Caveat: `polygon_tool.py` truncates `problem.testInput` at 20000 chars, so tail of the t=10000 file verified by construction only (header + generator assert), not direct parse.
  - Optional (non-blocking): mid-array-pinned unique-crossing variant; a t=10⁴ file with n∈{1..4} instead of n=20.
  - Checker is custom case-insensitive word compare — matches the Yes/No spec.
  - API calls used: ~10 (2 viewFile, 8 testInput incl. 1 retry after a timeout).
  ```

### ✓ coder: H 586694 rlu-cache-easy
- **Model:** my-local-server:kimi-k3 | **Duration:** 3m 48s | **Turns:** 12
- **Tokens:** ↑356k ↓6.6k | **Cost:** $0

  **Output:**

  ```
  Validator and gen fetched. Now sample actual test inputs (last 3 + mid ones).
  Rate-limited (429). Test 22 confirmed `gen maxt` (t=200000, n=q=1). Waiting and retrying serially.
  Test 24 is tiny (n=200000, q=1). Outputs are truncated at 20000 bytes — check the tool and whether it supports pagination.
  Truncation is in the tool — 20000 bytes per response. Enough to verify each test's header + structure; gen determinism covers the rest. Quick analysis of fetched data:
  All data gathered. Writing the review.
  **VERDICT: PASS** — H 586694 rlu-cache-easy. Full review at `review/H_testreview.md`.
  
  - Validator (1036 B) enforces **every** stated bound: t, n, q, Σn, Σq, a, b ranges, strict EOL/EOF. No gaps.
  - Bound attainment: all HIT — t=200000 (test 22), n=q=Σn=Σq=200000 (tests 16–21, 23), b=10⁹ pinned exactly in edge test; a→10⁹ via keymax=10⁹ random (999.6M observed), exact a=10⁹ never pinned (cosmetic only).
  - Edge coverage strong: n=1, capacity-1 eviction, update-existing, query-refresh trap (the statement's named common mistake, killed by edge test + WA-tagged witness), pure evict-storm (16), pure rank-churn (17), n≫q with keymax=3 (24).
  - TLE decisively killed: brute O(n)/query needs 4·10¹⁰ ops vs 2s TL on tests 16/17 (≥40–400× budget); `medsum` saturates sums for quadratic-per-test sols; verify-tagged package READY.
  - Only misses: unsolved — none real. Optional: pin a=10⁹ exactly; add a handcrafted max-scale evict-then-query (currently only statistical via rand tests).
  - Note: API returned HTTP 429 once (parallel fetches); retried serially, all 6 sampled tests fetched; responses truncated at 20 KB by the local tool, verified via headers + gen determinism.
  ```

### ✓ coder: I 591900 never-read-backwards
- **Model:** my-local-server:kimi-k3 | **Duration:** 4m 40s | **Turns:** 27
- **Tokens:** ↑769k ↓12k | **Cost:** $0

  **Output:**

  ```
  Script confirmed (13 tests). Now sources:
  Full local test copy exists — analyze all 13 tests directly:
  `_judge/I/tests` is a STALE/different problem's package — unusable. Regenerate deterministically instead (gen.cpp + testlib):
  The `cp` clobbered the API-fetched gen.cpp with the stale-package one. Re-fetch cleanly:
  Regeneration is byte-identical modulo CRLF. Compute per-variable maxima across all 13 tests:
  All regenerated; one huge finding already (max |s|=20000 vs statement 10⁴). Now check the 3 solutions briefly (CRLF trap + what sol_wa encodes):
  All evidence gathered. Writing the review:
  VERDICT: **GAPS** — review at `review/I_testreview.md` (PID 591900, 13 tests, verified via byte-identical local regen of all script lines).
  
  - **BLOCKER: |s| bound mismatch.** Statement promises |s| ≤ 10⁴, but validator allows 2·10⁴ and test 13 (`gen max 1`) contains 50 lines of **exactly 20000 chars** — official tests VIOLATE the published constraint. Fix statement (→2·10⁴) or shrink gen.
  - Validator Σ bound mismatch: enforces ≤2·10⁶ vs stated ≤10⁶ (tests stay at ≤10⁶, so latent; error message also lies about the bound).
  - All other bounds genuinely HIT: t=100 (tests 11,12), m=100 (9,11,12), Σ=10⁶ exactly (test 13), min len 1 / m=1 / t=1 (test 2 etc).
  - Edge cases good: palindromes, no-space lines, CRLF consistent, WA sol (line-order reversal) correctly rejected; no TL solution but none exists for O(Σ) — defensible.
  - Missing: INVALID validator tests (bad char, lead/trail space); m=100-with-long-lines file (low priority).
  - Note for future audits: `polygon_tool.py` truncates testInput at 20000 chars; `_judge/I/tests` is a stale dir of a DIFFERENT problem — trust API + local gen regen only.
  ```

### ✓ coder: J 584874 dp-math-hard
- **Model:** my-local-server:kimi-k3 | **Duration:** 3m 45s | **Turns:** 19
- **Tokens:** ↑485k ↓9.9k | **Cost:** $0

  **Output:**

  ```
  Script has only 10 lines. Now test list and validator/gen source.
  Cache script shows only 10 lines but there are 34 tests — cached script is truncated. Fetch the real script + validator + gen via API.
  Validator and gen retrieved — validator enforces every bound. Now sampling actual test inputs: tests 23 (sumpack), 27 (maxpairs), 31 (antitl), 32 (divmax), 33, 34 (tmax).
  All exactly 20001 bytes — likely truncated previews. Checking:
  API truncates `testInput` at 20000 chars — a display limit. Headers + leading content still verifiable. Analyzing all fetched previews:
  VERDICT: PASS — review written to contest/review/J_testreview.md
  
  - Validator: complete — t≤1e5, n≤1e5, Σn≤1e5 (incremental ensuref), a_i∈[±1e9], strict EOL; zero gaps.
  - Bounds hit (verified via testInput headers): t=1e5 (test 34 tmax), n=1e5 (tests 27/32), Σn=1e5 (test 23 = 20×5000 exactly), a_i=±1e9 (tests 27/34).
  - int64 trap present: divmax S≈6.98e13 near 1e14 cap; S=0 branch covered incl. 2^49999 mod stress.
  - Anti-hardcode: pinned cut-index sweep (16 tests, n=2·prime) + 3 pinnedone near n≈1e5, with sol_hack_skip registered WA witness.
  - TLE: sol_tl verified TL by Polygon's own verified package; antitl/divmax ≥50x budget; sumpack saturates Σn for quadratic solutions.
  - API note: problem.testInput truncates at 20000 chars — all big tests verified by header n/t + leading content matching gen modes; no bound missed.
  - Only nit (not blocking): no t=50000×n=2 reset-bug file (tmax uses n=1 only); script would take it as a 1-line add.
  ```

### ✓ coder: K 581736 zero-segment
- **Model:** my-local-server:kimi-k3 | **Duration:** 3m 15s | **Turns:** 14
- **Tokens:** ↑580k ↓8.5k | **Cost:** $0

  **Output:**

  ```
  Validator and gen look thorough. Now I'll fetch actual test inputs and compute per-variable maxima programmatically.
  Raw inputs — but all files are exactly 20001 bytes, suggesting truncation in polygon_tool.py. Checking.
  All bounds attained. Writing the review.
  **K 581736 zero-segment — VERDICT: PASS** (rev 14, package 1492103 verified READY)
  
  - Constraints: t≤2e5, n≤2e5, 1≤k≤n, a≤1e9, Σn≤2e5, answer≤2e9 — validator enforces **every** bound (0 gaps), 7 validator tests registered.
  - Bound attainment: ALL HIT — t=2e5 (test 35), n=2e5 (31-34, 38-40), k=n=2e5 (34), a=1e9 (many), Σn=2e5 (9 files), answer=2e9 int64 trap (06, 34). Verified by parsing all 40 local package tests, prefix-matched against live API.
  - Anti-hardcode: 7 trap variants (swept pins, head/tail, distance-band, stride, top-D cluster) + 4 WA-tagged linear hack witnesses, all confirmed failing by package verification.
  - TLE: O(n²) brute = ~2·10¹⁰ ops on n=2e5 singles (~25-40x budget), TL tag verified; sum-saturating file 36 + t=2e5 reset-killer 35 present.
  - Only cosmetic gaps (no action needed): no k=n−1 case at exactly n=2e5 (covered at n=1e5 by test 37, kMode 3), and trap-3 pinned-R singles exist only at R=1e5/1.5e5 (could add R=30000 cheaply).
  
  Full review: `review/K_testreview.md`
  ```

### ✓ coder: L 590582 coral-loop
- **Model:** my-local-server:kimi-k3 | **Duration:** 3m 21s | **Turns:** 11
- **Tokens:** ↑355k ↓8.0k | **Cost:** $0

  **Output:**

  ```
  Now fetch the full script and sample actual test inputs:
  Confirm the small edgepack tests fully retrievable (exact ±1e9 values):
  All evidence in. Writing the review:
  VERDICT: **PASS** — review at `review/L_testreview.md` (rev 10, verified package, 42 tests).
  
  - Validator: zero gaps — t, n, q, Σn, Σq, |a|/|b|/|w|≤1e9, s<t≤n+1, strict EOL/EOF all enforced.
  - Bounds HIT (verified by fetching tests 2/4/5/6/20/31/40/41/42): n=3·10^5 (tests 31,40), q=3·10^5 (31,40), Σn=Σq=3·10^5 exact (41 sumpack), ±10^9 values incl. updates (2,4,6), n=2/q=1 (2,42), full-span center query (5).
  - **t never fully stressed**: tmax file emits 99991 tests vs 150000 achievable (n=q=2) — ~66% of max test-count stress.
  - Trap pins randomized per seed (8 files), not a systematic index sweep at max n — tiny hardcode-survival window remains.
  - No degenerate max test (n=3·10^5 all-zeros, all-query) guarding early-exit hacks.
  - TLE kill: brute O(n·q)=9·10^10 vs 4s on ten max files; sumpack buries per-test quadratics (history: main itself TL'd test 33 at rev 3).
  - Cosmetic: statement t≤3·10^5 unreachable given Σn≥2t cap (150000).
  ```

### ✓ coder: M 586483 dp-counting-med
- **Model:** my-local-server:kimi-k3 | **Duration:** 1m 58s | **Turns:** 9
- **Tokens:** ↑255k ↓5.7k | **Cost:** $0

  **Output:**

  ```
  Validator and gen look solid on paper. Now sample actual tests: last 3 (32, 33, 34) + mid/max ones (25, 26, 29).
  Raw inputs fetched. Let me inspect and compute per-variable maxima.
  All data gathered. Writing the review.
  **M 586483 dp-counting-med — VERDICT: PASS**
  
  - Validator enforces every bound (t≤300, n≤300, m≤n(n−1)/2, k≤10^18, sum n≤300, strict EOLN/EOF) + 8 validator tests; no gaps.
  - Bound attainment (computed from fetched tests 25/26/29/32/33/34): t=300 HIT (`many`), n=300 HIT (`max` ×5), sum n=300 HIT everywhere, k=10^18 HIT (t29, t34), k=1 HIT, m=0 HIT.
  - m relative bound: near-hit — max observed 44550 vs 44850 at n=300; m=mx exactly only for n≤16 (`edges 0`).
  - k == dp[n][m] equality boundary covered only at n=3 (sample1, edges 1); no crafted equality at large scale.
  - TLE: t25 (n=300, m=22425) kills O(n²·m) no-sliding-window (~100x budget); brute force dead by astronomic factor; split files (sum=300 over 2/3/6/10 parts) + `many` (t=300 of n=1) present.
  - Worst gaps (both minor): (1) add `gen max 5` = {300, 44850, 2} for the exact m-corner at max n → −1; (2) add one crafted k==count case at scale.
  - Full review: `contest/review/M_testreview.md`. API calls used: ~10.
  ```

## Total
- **Cost:** $0
- **Duration:** 8m 8s