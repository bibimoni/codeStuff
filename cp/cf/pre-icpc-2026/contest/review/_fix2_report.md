# Swarm Report: Verify I test13 + add J reset test + add M corner tests

**Mode:** swarm | **Tier:** auto | **Status:** completed

## Tasks

### ✓ coder: I2
- **Model:** my-local-server:kimi-k3 | **Duration:** 1m 52s | **Turns:** 12
- **Tokens:** ↑263k ↓5.5k | **Cost:** $0

  **Output:**

  ```
  viewFile returns raw source. Let me get metadata (sourceType) via problem.files and inspect the max mode.
  FINAL OUTPUT:
  - Verdict: **already-correct** — no changes made, no commit/build (per spec step 5).
  - Live gen.cpp `max` mode: `t=1, m=100, rndline(rnd,10000)` × 100 (exactly 10000 chars/line, spaces substituted in-place).
  - Local regen (`gen max 1`): 102 lines total; lines 3–102 (the 100 strings): min=10000, max=10000; grand total = 1 + 3 + 100×10000 = 1,000,004 chars (header 4 + data 1,000,000).
  - Live test 13 (problem.testInput, ~20KB API truncation): after stripping `\r`, byte-identical to local regen for all 19,997 content bytes; live string #1 = exactly 10000 chars (string #2 appears as 9990 chars purely due to API truncation at ~20KB).
  - Testset healthy: 13 tests, all manual=false, test 1 useInStatements=true.
  - Package: not rebuilt (nothing to fix).
  ```

### ✓ coder: J2
- **Model:** my-local-server:kimi-k3 | **Duration:** 3m 47s | **Turns:** 26
- **Tokens:** ↑705k ↓7.3k | **Cost:** $0

  **Output:**

  ```
  Now check local gen matches live, then add the `reset` mode.
  MA runs in 0.07s, 50000 outputs, deterministic gen. Now validate and cross-check with a leaked-state witness to prove the test has teeth.
  Validator VALID. Backward-compat spot check against live testInput (tests 1 and 34):
  Only CRLF vs LF difference from the API. Re-compare with `\r` stripped:
  Backward-compat confirmed (test 34 matches up to the API's 20000-byte truncation; test 1 full match modulo API-appended newline). Now upload and script:
  Live test 35 header matches local output exactly. Commit done; now build package:
  FINAL OUTPUT:
  - Problem J "dp-math-hard" (584874): tests 34 -> 35, all existing 34 script lines untouched (spot-check: test 34 `gen tmax` byte-identical through the API's 20000-byte cut; test 1 `gen sample1` identical).
  - gen.cpp gained `gen reset <seed>`: t=50000, all n=2 (sum n = 100000 exactly), pairs from {1,-1},{-1,1},{1,1},{-1,-1},{2,-1},{-1,2},{1,-2},{-2,1},{2,-2},{-2,2} (sums 0/±1-dominated), deterministic (10 runs, identical md5).
  - Live test 35 header confirmed: `50000\n2\n1 -2\n...` — matches local emission.
  - Local checks: validator VALID (exit 0); sol_main runs 0.07s on the file; leak-state witness differs on 13410/50000 lines (test has teeth).
  - Uploaded gen.cpp (cpp.g++17), script line `gen reset 1 > 35`; test 35 manual=false; committed "J: reset-bug killer (50000x n=2)".
  - buildPackage full=false verify=true -> READY in 41577ms "with verification" (tag witnesses all held).
  - Files touched locally: /Users/distiled/codeStuff/cp/cf/pre-icpc-2026/dp-math_hard/gen.cpp only; scratch in /tmp/fix_J.
  ```

### ✓ coder: M2
- **Model:** my-local-server:kimi-k3 | **Duration:** 8m 32s | **Turns:** 42
- **Tokens:** ↑1468k ↓25k | **Cost:** $0

  **Output:**

  ```
  Local dump exists. Now let me fetch the live state from Polygon (script, gen.cpp, tests).
  Live script has 34 lines. Now fetch live gen.cpp, validator, and MA solution.
  Live gen.cpp = local + trailing blank line. Now read validator and fetch sol_main.
  Problem, validator, and MA solution all clear. Now edit gen.cpp (working on the live copy, keeping its trailing blank line).
  cnt(300,3) = 4,499,650 (≈ n³/6, plausible). Now validate + run MA + brute-check the count.
  Mismatch — inspect what's actually in the live test inputs.
  pin1 = old1 modulo CRLF. pin15 differs numerically → local testlib's `rnd` stream differs from Polygon's build (known testlib-version seeding difference). Verify with deterministic modes after stripping CR:
  Tests 1 and 25 match byte-for-byte (modulo CRLF + the tool's trailing newline). Backward compatible. Now build the new script and upload.
  Polygon's compile rejects `__int128`. Replace with a direct saturating-sum DP (exact until cap 2e18, no subtraction corruption possible):
  36 tests, all generated (`manual=false`). Confirm live content of the two new tests, then commit + build.
  Package is READY with `verify=true` — all 36 tests validated and all 4 solution tags confirmed by Polygon. Done.
  
  FINAL OUTPUT:
  - Tests: 34 → 36. Added `gen mcorn > 35` (= `1 / 300 44850 2`, exact m-max corner) and `gen kequal 300 3 > 36` (= `1 / 300 3 4499650`); live `problem.testInput` confirms both contents; tests 35/36 are `manual=false`.
  - gen.cpp: added two additive modes (`mcorn`, `kequal`); old modes untouched — spot-checked tests 1 (`sample1`) and 25 (`max 0`) byte-identical vs `problem.testInput` (modulo CRLF/tool trailing newline). Polygon's compile rejects `__int128`, so the capped count DP uses exact `long long` saturating sums (cap 2e18, fall back k=1e18 if >1e18).
  - Local verification: both new inputs VALID under the live validator; gen DP count brute-verified at (n,m) = (5,4)=20, (8,3)=76, (9,5)=628, (8,10)=2493; MA cross-checked to pick lex-last at n=8,m=3.
  - MA outputs: test 35 → `-1`; test 36 → valid permutation of 300 with exactly 3 inversions (counted; lexicographically last among m=3 permutations).
  - Package: 1492279 (revision 7), state READY, full=false verify=true.
  - Committed: "M: exact m-max corner + k==count equality test". Only problem 586483 (M) touched.
  ```

## Total
- **Cost:** $0
- **Duration:** 8m 32s