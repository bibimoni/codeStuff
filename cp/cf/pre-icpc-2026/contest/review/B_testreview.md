# Test-quality review — B 585524 "grid-reboot" (Blackout on the Neural Grid)

Problem: toggling vertex u flips u and its neighbors (GF(2) linear system
A·x = b with A = adj+I). Single-test input format (NOT multi-test): one line
`N M Q`, M edges, then Q scenario lines, each N bits. TL 3000 ms / ML 512 MB.
Custom checker (any valid toggle set accepted). Latest package READY, built
"with verification". Solutions roster: solution.cpp (MA, one augmented
elimination [A|b1..bq] with bitsets), gemini.cpp (OK), TLE1.cpp (TL,
per-query elimination), greedy1-4.cpp (RJ). Good roster.

Method: full local package `_judge/B/tests` (101 inputs + jury answers)
parsed exhaustively; test 101 cross-checked against live
`problem.testInput` (token-prefix identical; endpoint truncates at ~20 KB,
noted). API calls used: 4.

## Constraints (extracted from statement)

| Variable | Bound | Notes |
|---|---|---|
| N | 1 ≤ N ≤ 3000 | vertices |
| M | 0 ≤ M ≤ 3000 | undirected links, u≠v, **no duplicate links** |
| Q | 1 ≤ Q ≤ 500 | scenarios |
| u, v | 1 ≤ u,v ≤ N | |
| scenario | N chars ∈ {0,1} | statement says "a string of N characters" |
| output | -1, or K (0 ≤ K ≤ N) + K distinct 1-indexed ids | |

Single test per file: no t, no sum-over-tests bounds; t/multi-test N/A.

## Validator coverage

validator.cpp checks ALL stated bounds: N∈[1,3000], M∈[0,3000], Q∈[1,500],
u,v∈[1,N], u≠v (ensuref), undirected duplicate rejection via canonical
(min,max) set, N values 0/1 per scenario with exact spacing/EOL, EOF.
✓ No declared-but-unchecked bound.

**FORMAT MISMATCH (must fix):** the statement promises each scenario as "a
string of N characters" (contiguous, e.g. `0101`), but the validator
READS N space-separated integers, and gen/sample/test data are all
space-separated (`0 0 0 1 1 1 1`). A contestant who follows the statement
and reads one token as the whole line (getline / `string s; cin>>s;` and
index s[0..n-1]) breaks on real data. Either reword the input section to
"N space-separated integers" (matches everything) or switch data to
contiguous strings. Also: 0 validator tests and 0 checker tests are
registered on Polygon (both lists empty).

Checker: correctly simulates toggles and compares against jury -1/_fail
semantics; **does not enforce "distinct"** — duplicate indices in the
contestant list are silently accepted (toggle twice = cancel), violating
the stated "K distinct integers". Minor accept-side hole.

## Bound attainment (from ALL 101 real test inputs)

| Variable | Stated bound | Observed min / max | Verdict |
|---|---|---|---|
| N | ≤ 3000 | 4 / **2926** | **MISS** — n=3000 absent; only 3 tests n≥2900 (2926, 2925, 2925) |
| M | ≤ 3000 | 4 / **2976** | **MISS** — m=3000 absent |
| Q | ≤ 500 | 5 / **499** | **MISS** — q=500 absent (9 tests q≥450) |
| N = 1 | min corner | never (gen starts at 2; sample n=7) | **ABSENT** |
| M = 0 | min corner | never (gen forces m≥1) | **ABSENT** |
| Q = 1 | min corner | never (min observed 5) | **ABSENT** |
| joint worst (n≈3000 ∧ q≈500) | (3000,500) | best: (2868, 489) — test 31 | near-miss only |

Root cause: gen.cpp ignores its arguments; script is `gen 1 <seed>` ×100,
so every parameter is a uniform dice roll per seed — exact bounds are
never pinned. Secondary effect: max scenario answer K observed = 1522,
so the max-output extreme (K=N=3000) is also untested.

## Edge cases present

- Sample: exercises success, alternate optima, K=0, and -1 (5 queries, n=7).
- -1 (impossible) answers: 14 114 scenarios across 70 of 101 files — very well covered (statistically, via singular random matrices).
- K=0 (already all-online): 14 scenarios in 2 files — present **by luck only** (14 all-ones strings among ~25k random scenarios).
- All-zero scenario strings: 10 scenarios in 2 files — also luck only.
- Disconnected graph: 27 files; isolated (degree-0) vertices: 27 files.
- Structural variety: line 10% / star 10% / grid 20% / dense-small 30% / sparse-random 30%.
- Small-n: 40 files with n<500, min n=4.

## Edge cases MISSING

1. **Exact-max corner**: no file with n=3000, m=3000, q=500 — a static-buffer hack (`bitset<2950>`, `int a[2500]`) passes the entire set. Add one full (3000, 3000, 500) file.
2. **n=1, m=0** — minimum corner (answer always exists: toggle the 0-terminals).
3. **m=0, n large** — all vertices isolated; forces the complement answer with K up to 3000 (max output size, also untested: max K observed 1522).
4. **q=1**.
5. Deterministic handcrafted all-ones (K=0) and all-zeros (K=full) scenarios — currently luck-dependent; a reseed could silently drop them.
6. Anti-hardcode sweeps in the classic pinned-index sense don't apply to a GF(2) system (solutions move with the matrix), but the missing exact-bound tests leave size-cap hacks alive — item 1 covers this.
7. Registered validator tests and checker tests on Polygon: both lists empty (add VALID sample + INVALID per constraint class: dup edge, self-loop, q=0, m=3001, bad char/length; checker OK/WA shapes incl. duplicate-index rejection, -1-when-solvable, solvable-when-jury--1).

## TLE-killer analysis

- TL solution TLE1.cpp = per-query GF(2) elimination O(Q·N³/64). Cost driver n·q: best current tests are #31 (n=2868, q=489), #88 (2162, 499), #15 (2499, 429), #52 (2195, 487), #66 (2836, 366) — five files with n·q ≈ 10⁶ → ≈ 9·10¹⁰ word-ops, ≥25× over the 3 s TL. **Per-query elimination is decisively rejected.** A non-bitset brute is even deader. No honest brute force can plausibly pass. OK.
- MA solution worst file: ~2·10⁸ word-ops (augmented width n+q) ≈ 15–20% of TL — comfortable.
- Volume adequacy: worst file ≈ 89% of true worst-case volume; acceptable for asymptotic rejection, but see Gap 1 — no terminal test at 100% of the stated box.

## VERDICT: GAPS

Validator is complete and the set kills the intended TLE solution, but
**not a single declared bound (n=3000, m=3000, q=500, n=1, m=0, q=1) is
hit by any test**, and the statement's scenario format contradicts every
test/validator/checker/gen.

Concrete fixes, in priority order:
1. Fix statement input format ("N space-separated integers 0/1") — or regenerate data as contiguous strings; statement and data must agree.
2. Add `n=3000, m=3000, q=500` random file (exact max corner; kills buffer-cap hacks).
3. Add `n=1, m=0, q=500` (mixed strings) and `n=3000, m=0, q=500` (incl. all-zero scenario → K=3000 answer) files.
4. Add handcrafted medium file with pinned all-ones (K=0) and all-zeros (K=n) scenarios.
5. Enforce index distinctness in checker.cpp; register validator tests + checker tests on Polygon.
