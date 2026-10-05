# Test-quality review — H 586694 rlu-cache-easy ("Humble RLU Cache")

TL 2000 ms / ML 256 MB. Multi-test. Checker: exact int64-sequence compare (`ncmp`-style, checker tests OK/WA pass).
Latest package: rev 8, **READY, built with verification** — MA/OK/TL/WA tags all confirmed by Polygon.

## Constraints (from statement)

| Variable | Bound | Role |
|---|---|---|
| t | 1 ≤ t ≤ 2·10⁵ | # test cases |
| n | 1 ≤ n ≤ 2·10⁵ | cache capacity; cache starts full with keys 1..n, value 0 |
| q | 1 ≤ q ≤ 2·10⁵ | queries per test |
| Σn | ≤ 2·10⁵ | sum over tests |
| Σq | ≤ 2·10⁵ | sum over tests |
| a (key) | 1 ≤ a ≤ 10⁹ | put/get key |
| b (value) | 1 ≤ b ≤ 10⁹ | put value |

Output: per type-2 query, `b r` or `-1`. Order r ∈ [1, n]. All answers fit int32, but products/ordering do not overflow — no 64-bit trap needed (values ≤ 10⁹, r ≤ n ≤ 2·10⁵).

## Validator coverage (validator.cpp, 1 KB)

Checks: t ∈ [1, 2·10⁵]; per test n, q ∈ [1, 2·10⁵]; running Σn ≤ 2·10⁵ and Σq ≤ 2·10⁵ enforced *inside* the loop (ensuref); each query line: type ∈ {1,2}, a ∈ [1, 10⁹], b ∈ [1, 10⁹] if type 1; strict readSpace/readEoln/readEof; setTestCase for diagnostics.
**Gaps: none.** Every stated bound is validated, including both sum guarantees and exact whitespace/EOL/EOF.

## Generation script (24 tests)

Modes used: `sample` (1), `edge` (2: 10 handcrafted micro-cases incl. capacity-1 eviction, query-refresh-saves-key, value update ×2, b=10⁹), `queryonly` (3: rank churn on initial keys, no adds), `mini` 1–2 (4–5: 200 tiny random tests each), `rand` with swept (t, n, q, keymax, addpct, seed) (6–15, 19–21, 24), `storm` (16: n=q=2·10⁵, all type-1 distinct fresh keys → eviction on every add), `churn` (17–18: all type-2 on keys 1..n → max rank work, no eviction), `maxt` (22: t=2·10⁵ of n=1 q=1), `medsum` (23: 200×(n=1000,q=1000), saturates both sums).
Confirmed against API: test indices ↔ script lines match the cached list; all `manual=false`; test 1 is the only statement sample.

## Bound attainment (fetched tests 16, 17, 19, 22, 23, 24; API truncates bodies at 20 KB, headers + prefixes verified, rest deterministic from gen)

| Variable | Stated bound | Observed max | HIT/MISS |
|---|---|---|---|
| t | 2·10⁵ | 200000 (test 22 header) | **HIT** |
| n | 2·10⁵ | 200000 (tests 16, 17, 19, 20, 24 headers) | **HIT** |
| q | 2·10⁵ | 200000 (tests 16, 17, 19, 20) | **HIT** |
| Σn | 2·10⁵ | 200000 (16–20: single max tests; 23: 200×1000 = 200000) | **HIT** |
| Σq | 2·10⁵ | 200000 (same files) | **HIT** |
| b | 10⁹ | 10⁹ exactly (test 2, `add(10, 1000000000)`); 999+ M in rand tests | **HIT** |
| a | 10⁹ | 999570459 in 20 KB prefix of test 19; keymax=10⁹ in tests 8, 11, 15, 19, 21 | **HIT (random)**, exact a=10⁹ never pinned — see gaps |
| min values (n=1, q=1, a=1, b=1) | 1 | edge/mini/sample cover all | **HIT** |

## Edge cases

Present: n=1 (sample case 2, edge ×5, maxt ×2·10⁵) · n >> q (test 24: n=2·10⁵, q≤5) · capacity-1 eviction · update of existing key (no eviction, value replaced) · update twice · **query-refresh semantics** (type-2 hit refreshes key — the statement's named common mistake; edge case `get(1), add(3,5), get(1), get(2)` kills it; sol_wa is exactly this bug and verify rejects it) · evict initial keys in order · pure-churn (all type-2, no eviction) · pure-storm (all type-1, eviction every add, keys n+1..n+q) · keys crowded into tiny range with huge n (test 24: keymax=3, n=2·10⁵) · b=10⁹ · t=MAX with degenerate minimal tests (I/O + per-test state reset).

Missing / weak: **(a)** exact a = 10⁹ key never pinned (only random keymax=10⁹; P(hit exactly) ≈ 1e-4 per file) — near-zero risk for this problem since keys are just hash-map indices, listed for completeness; **(b)** no explicit "type-2 query on a key *just evicted* immediately before" at max scale (covered at micro scale in edge; storm implicitly produces this pattern: every old key is queried-never after eviction… actually storm has zero type-2; churn has zero type-1; the mixed large tests 19–21 rely on randomness to produce evict-then-query sequences — with q=2·10⁵ adds over keymax=2·10⁵ ≈ n, evict-then-query is statistically guaranteed). Not a real gap.

Anti-hardcode: not applicable in the classic pinned-index sense (output = full deterministic simulation); the simulational nature itself defeats single-point hacks. `sol_wa` (drops lookup-refresh) is the registered wrong-idea witness, rejected by verification.

## TLE-killer analysis

Intended: O((n+q) log(n+q)) (Fenwick + set + hash map).
Brute (sol_tl): O(n) per query — worst 2·10⁵ × 2·10⁵ = 4·10¹⁰ elementary ops vs ~10⁸–10⁹ feasible in 2 s ⇒ **≥40–400× over budget** on tests 16/17 (n=q=2·10⁵ single test). That's ≥50×. ✔
Per-test-quadratic saturation: test 23 (`medsum`) gives 200 × (1000×1000) = 2·10⁸ ops for any O(n·q) per-test solution — borderline-to-slow; combined with tests 16/17 the TL tag is decisively enforced (package verify confirms sol_tl gets TL, not WA).
No honest brute force passes: any O(n)/query or O(n+q) per *query* approach dies on 16/17; nothing in the set is weak enough to admit them (smallest large file is 21: 2 × 10⁵ queries each).

## VERDICT: **PASS**

Complete validator coverage; every bound (t, n, q, Σn, Σq, b) is hit exactly by construction and confirmed in fetched inputs; both pathological operation mixes (pure evict-storm, pure rank-churn) and sum-saturating files exist; the named semantic trap is covered by handcrafted edge tests; TL/WA/OK/MA tags verified by a READY package built with verification.

Optional (not required) additions: pin a = 10⁹ exactly in `edge`; a large handcrafted evict-then-query-miss at max scale as a non-random witness. Neither is a real hole.
