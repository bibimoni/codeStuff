# Swarm Report: Add WA/TL witness solutions to A and F

**Mode:** swarm | **Tier:** auto | **Status:** completed

## Tasks

### ✓ coder: A4
- **Model:** my-local-server:kimi-k3 | **Duration:** 11m 0s | **Turns:** 27
- **Tokens:** ↑975k ↓21k | **Cost:** $0

  **Output:**

  ```
  Script has 43 gen lines (tests 4..46) + 3 manual samples = 46 tests. Fetch the MA solution and rest of gen.cpp:
  Problem understood: given suffix-array permutation p, answer = 1 + #{i: pos[p[i]+1] > pos[p[i+1]+1]}. Get testlib, samples, time limit:
  testInput returns raw. Just dump it:
  TL=1000ms, samples fetched. Now set up scratch dir, save live gen.cpp, compile with testlib, regenerate all tests locally:
  Mac clang lacks bits/. Use portable includes (fine for Polygon g++ too):
  MA formula matches samples (test3=4 — hand-checking error mine, code consistent). Now write brute + WA + TL:
  MA==brute on 993 cases. Now run WA and TL across all 46 tests:
  `timeout` doesn't exist on macOS — use a python wrapper for TL checks:
  TL times out on n=50 tests as required. Full sweep with output comparison:
  TL: correct on all 36 tests it finishes (samples + all n≤10), TLE on 10 tests with n=35..50. WA: wrong on test2 onward. Upload both solutions:
  Wrong key. Inspect the packages payload structure:
  Package READY rev 13 with verification. Confirm final roster + test count:
  FINAL OUTPUT:
  
  - **Heuristic (sol_wa.cpp, tag WA)**: answer = 1 + #descents in p. Killing evidence: disagrees with truth on the current live testset already — test2 (sample, p=[4,3,2,1]: truth 1 via "aaaa", heuristic 4), plus 41/46 files differ locally; fails fast on test2. No script line needed; testset untouched.
  - **Ground truth**: brute-force (exhaustive k^n strings, k ascending, n≤8) matched MA formula 1+#{i: pos[p[i]+1]>pos[p[i+1]+1]} on 993 permutations (all perms n≤6, 120 random n∈{7,8}) — 0 mismatches.
  - **TL (sol_tl.cpp, tag TL)**: exhaustive 2^{n-1} enumeration of LT/EQ gap masks (EQ valid iff tail-rank condition; letters = 1+#LT) — provably correct (it enumerates the exact design space of the closed form), Ω(2^n). Local: output == MA on all 36/46 tests it finishes within 3s (all 3 samples + every n≤10 edge); times out (>3s) on 10 tests with nmax 35..50 — 2^49 iterations at n=50 vs 1000ms TL.
  - Uploads: both files with observed sourceType `cpp.gcc14-64-msys2-g++23`; commitChanges done (message "A: WA heuristic + TL exponential witnesses").
  - Tests count: **46** (3 manual + 43 generated; samples 1–3 still `useInStatements=true`).
  - **Package state: READY** — id 1492493, rev 13, "Package created in 61482 ms **with verification**" (verify=true ⇒ MA/OK pass all, WA took WRONG_ANSWER, TL took TIME_LIMIT; a tag violation would have FAILED the build). No FAILED iteration was needed.
  ```

### ✓ coder: F4
- **Model:** my-local-server:kimi-k3 | **Duration:** 7m 36s | **Turns:** 36
- **Tokens:** ↑1230k ↓18k | **Cost:** $0

  **Output:**

  ```
  gen.cpp, samples, roster all fetched. Now set up scratch: compile gen, regenerate all 38 tests, write WA/TL solutions.
  The `gen` binary didn't get created (compile issue?) and empty test files were made. Checking:
  All 38 tests regenerated. Now the solutions:
  out/ dir race on first iteration. Redoing cleanly:
  `timeout` missing on macOS. Using perl/python wrapper:
  TL matched everywhere — suspicious, n=100 should TLE. Timing test 31 directly:
  6ms for a C(100,7) walk is impossible — something's off. Instrumenting:
  n is random in [7,nmax], not fixed — test 31 drew n=29. Checking actual n values per test:
  Max live n is 53 (tests draw n ~ U[7,nmax]), so a bare C(n,7) walk with early-exit finishes everywhere. Rewriting sol_tl to do unconditional full-verification per subset and no early exit:
  Local bar met: WA wrong on all 38 (incl. both samples), TL==MA everywhere it finishes, TLE on test 35. Uploading:
  Package READY with verification. Final confirmation of roster/tests:
  FINAL OUTPUT:
  1. F (snow-white, id 586329): added sol_wa.cpp (tag WA) + sol_tl.cpp (tag TL), sourceType cpp.gcc14-64-msys2-g++23; roster now MA/OK/OK/WA/TL.
  2. WA idea: finds the correct height (freq==7) but prints the 7 names SORTED instead of input order. O(n log n), wrong on ALL 38 live tests (regen'd locally from live gen.cpp+script; kills start at samples 1 & 2, e.g. sample 1: sorted "city for just of shining stars you" vs input order).
  3. TL idea: enumerate all C(n,7) 7-subsets, all-equal check + per-member full rescan verifying count==7, no early exit (~7·n·C(n,7) ops). Correct & fast ≤2s on tests 01–34,36–38 (37/37 match MA; n≤~41); times out on test 35 (n=53, C(53,7)≈1.5e8 → 2.32s local M-series, decisively >2s on judge). Note: live tests draw n~U[7,nmax], so true max live n is 53, not 100.
  4. Local verify: WA≠MA on 38/38; TL==MA on every test finishing ≤2s; zero mismatches.
  5. Remote: committed ("F: WA output-order + TL subset-enumeration witnesses"), buildPackage full=false verify=true → package 1492491 READY "with verification" on first try; tags asserted (WA wrong somewhere, TL TLE somewhere).
  6. Tests count: 38 (samples = tests 1,2 flagged); no script/test changes needed.
  
  Files: /tmp/fix_F4/{sol_wa.cpp,sol_tl.cpp,sol_ma.cpp,gen.cpp,script.txt,tests/} — scratch only; no repo changes.
  ```

## Total
- **Cost:** $0
- **Duration:** 11m 0s