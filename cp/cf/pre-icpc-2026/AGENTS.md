# Polygon Problem Creation Playbook

How to turn a sibling directory containing `raw_statement.md` into a complete,
verified Polygon problem. Any agent can pick up a new problem by reading this
file plus the target problem's `raw_statement.md`.

## Layout

```
pre-icpc-2026/
  AGENTS.md                 <- this file
  secret                    <- Polygon API credentials (Name/Key/Secret lines). NEVER print it.
  polygon_tool.py           <- signed Polygon API client (see below)
  Polygon API documentation.md
  <problem-dir>/
    raw_statement.md        <- the only required input: problem + constraints + solution idea
    statement/*.tex-ish     <- legend/input/output/notes/tutorial bodies
    validator.cpp  checker.cpp  gen.cpp
    sol_main.cpp (MA)  sol_ok.cpp (OK)  sol_tl.cpp (TL)  sol_wa.cpp (WA)
    script.txt              <- generation script for testset "tests"
```

## API client

All calls go through `polygon_tool.py` (handles SHA-512 apiSig auth +
`@file` expansion, prints JSON, exits non-zero on status FAILED):

```bash
PY=../polygon_tool.py                      # from the problem dir
python3 $PY problems.list                  # smoke test
python3 $PY problem.<method> problemId=$ID k=v ...
```

Signatures, endpoints, object shapes: see `Polygon API documentation.md`.
Params after the method name are `key=value`; `key=@path` reads the value from
a file. Booleans are the strings `true`/`false`.

## Workflow (run in order; each step depends on the previous IDs)

1. **Design first.** From raw_statement.md pin down: exact I/O format
   (default: multi-test, see Conventions), ALL constraints incl. sum-over-tests
   bounds, the correct solution, 1 plausible WA idea, 1 correct-but-TLE idea.
2. **Local materials.** Write statement bodies, `validator.cpp` (testlib,
   checks every bound incl. sum-of-n and exact whitespace/EOL),
   `checker.cpp` (exact-match int64 sequence via testlib is enough for
   unique answers), `gen.cpp` (testlib generator: hardcoded named modes for
   samples/edges + a parametric `rand` mode), solutions, `script.txt`.
3. **Local sanity.** Compile solutions/clang, run main solution on samples,
   cross-check main vs a dumb brute on small random tests, and run the TL
   solution once against a max-size input to confirm it really is slow.
4. `problem.create name=<slug>` -> store the returned `id`.
5. `problem.updateInfo problemId=$ID timeLimit=<ms> memoryLimit=256`
6. `problem.saveStatement problemId=$ID lang=english name=... legend=@... input=@... output=@... notes=@... tutorial=@...`
7. `problem.saveFile problemId=$ID type=source sourceType=cpp.g++17 name=<f> file=@<f>` for validator.cpp, checker.cpp, gen.cpp.
8. `problem.saveSolution problemId=$ID name=sol_main.cpp file=@... tag=MA` (+ OK / TL / WA addons; `sourceType=cpp.g++17`).
9. `problem.setValidator problemId=$ID validator=validator.cpp` and
   `problem.setChecker problemId=$ID checker=checker.cpp`
   (custom checker: upload it as a source file first; standard ones like
   `std::ncmp.cpp` may also work, custom is deterministic).
10. `problem.saveScript problemId=$ID testset=tests source=@script.txt`
    then verify with `problem.tests problemId=$ID testset=tests` — count must
    match the script lines, every `manual=false`.
11. Flag samples: `problem.saveTest problemId=$ID testset=tests testIndex=1 testUseInStatements=true verifyInputOutputForStatements=true` (repeat per sample).
12. `problem.saveTags problemId=$ID tags=greedy,implementation` (CF tag vocabulary, comma-separated, no spaces).
13. (Optional but do it) validator tests: `problem.saveValidatorTest problemId=$ID testIndex=N testInput=@... testVerdict=VALID|INVALID` — one VALID sample + one INVALID per constraint class (k>n, a_i out of range, sum violated, t=0, junk EOL). Checker tests: `problem.saveCheckerTest ... testVerdict=OK|WRONG_ANSWER`.
14. `problem.buildPackage problemId=$ID full=false verify=true` then poll
    `problem.packages problemId=$ID` every ~15 s until `state` is
    READY or FAILED. verify=true runs the validator on all tests and all
    solutions on all tests, asserting their tags — this is the real check.
15. If FAILED: fetch the failing piece (package comment / invocation), fix
    locally, re-upload the one changed file, rebuild. Never paper over a
    validator or tag error by weakening tests.
16. `problem.commitChanges problemId=$ID minorChanges=true message="Initial version (API)"`.

## Conventions (defaults; deviate only if raw_statement forces it)

- **Multi-test input**, always:
  ```
  t
  n [other params...]
  <test data>
  ```
  with a stated guarantee "sum of <size> over all test cases <= MAX". State
  `t`'s own bound too (`t <= MAX`). Output: one answer per test case.
  Validate the sum guarantee in validator.cpp AND respect it in gen.cpp
  (compute worst-case products before writing script lines).
- **TL/ML**: 2000 ms / 256 MB unless the main solution is within 4x of that.
- **Solutions roster**: `sol_main.cpp` (MA, the intended one), `sol_ok.cpp`
  (OK, correct alternative/slower-but-passing, catches model-solution bugs),
  `sol_tl.cpp` (TL: the natural brute force — must be CORRECT, just slow),
  `sol_wa.cpp` (WA: the most tempting wrong idea, e.g. dropped edge case or
  too-greedy heuristic). Names tell tags; Polygon verify confirms them.
- **Checker**: exact int64-sequence compare when answers are unique. Only
  write a real checker (multiple valid outputs) when the problem needs one —
  then add checker tests for every accepted/rejected shape.
- **Tags**: CF vocabulary (greedy, implementation, math, dp, graphs, ...).
- Samples come first (tests 1, 2, ...) as hardcoded `gen` modes so the script
  fully determines the testset; flag them with `useInStatements`.

## Test design doctrine (the 30/50/20 rule)

Roughly, by test count — adapt to the problem:

- **~30% small**: every edge case, handcrafted: n=1, params at min/max of
  their ranges, k=1 / k=n style extremes, all-equal values, sorted/reverse
  sorted, answer-nulling special cases (e.g. degenerate formula branch),
  64-bit-overflow traps (max value answers), value 1 / value MAX corners.
  Prefer several tiny cases bundled per multi-test file.
- **~50% medium**: random tests from n~50 to a few thousand, multiple files
  per structural pattern (random, monotone, equal, clustered/trap patterns,
  extreme parameter mixes). These kill wrong logic that passes edges.
- **~20% max-bound**: kill TLE decisively. Include: single max-n tests of
  several patterns; one file with t=MAX of minimal tests (I/O + per-test
  reset bugs); one file with sum=MAX split over medium n (hurts quadratic
  per-test solutions); worst input for any heuristic an experienced
  contestant would try under time pressure. If a TL-tagged solution must be
  rejected, ensure at least one max test is >=50x over its asymptotic budget.
  Never make the MAIN solution's worst file exceed ~40% of TL locally.

Add a trap test for every wrong idea you can name; turn the named idea into
`sol_wa.cpp` and prove verify rejects it.

**Anti-hardcode traps**: random tests can NEVER catch single-point corruption
hacks (`if (i == 500) continue;` and friends). Add tests with a pinned UNIQUE
optimum at swept indices (e.g. exactly two 1s at (L, R), L = R-k+1, rest
max-value; R sweeps the mid-array range in a medium file plus a couple of
n=MAX singles). Any index-targeted skip inside the swept range then provably
dies; keep the hack as a WA-tagged solution as a permanent regression witness
— buildPackage(verify=true) fails loudly if a future testset edit ever
re-admits it. Sweep more than indices: pin the optimum at swept DISTANCE
offsets beyond k-1 (kills distance-band heuristics "only check j near
i+k-1" and stride heuristics "every W-th j"), pin near array start/end
(kills head/tail cutoffs), and add clustered-minima tests (kills
"only pair among the D smallest values" filters for D <= cluster size).
Keep registered hack solutions LINEAR-time: a quadratic hack takes TL on
max tests, and a TL verdict VIOLATES its WA tag (build fails) — the
realistic cheaters dodge TL anyway, so write them as linear filters.

## Gotchas learned the hard way

- Sign params are sorted by (key, value); apiSig = rand(6) + sha512 hex of
  `rand/<method>?<qs>#<secret>` where qs is the RAW (NOT percent-encoded)
  `key=value&...` string — signing the encoded form gives "Incorrect
  signature" as soon as any value has spaces/commas. The POST body itself
  stays urlencoded (polygon_tool.py does both correctly).
- `problem.saveScript` regenerates the testset; generated tests keep indices
  by order. Rerunning replaces generated tests (manual tests persist).
- Editing a generated test via saveTest with only flags (no testInput) does
  NOT turn it manual.
- updateInfo/saveStatement/saveFile params are all optional on edit — send
  only what changes.
- sourceType for C++17: `cpp.g++17`.
- If the account's problem is fresh, testset name is `tests`.
- Fresh problems: buildPackage fails with "Commit the changes before
  packaging" — commitChanges first, then build, and commit after every
  fix round.
- Inputs saved via API (checker/validator tests) keep exactly what you send:
  a missing trailing newline makes the validator FAIL the input ("Expected
  EOLN") and the run shows as CRASHED. End every testInput with `\n`.
- Never upload a local testlib.h copy — Polygon compiles against its own
  (fetch testlib.h locally only to compile/run checks on your machine).
- buildPackage(verify=true) is the acceptance test; a READY package with
  verified tags is "done", not before.
