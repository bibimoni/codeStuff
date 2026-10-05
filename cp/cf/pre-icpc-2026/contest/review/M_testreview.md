# Test-quality review — M 586483 dp-counting-med ("M-th Permutation by Inversions")

TL 2000 ms / ML 256 MB. 34 tests, all generated from `gen.cpp` (0 manual), 1 sample in statements (test 1; test 2 = `sample2` generated but not flagged into the statement — acceptable).
Latest standard package (rev 6) built **READY with verification**; solutions roster MA/OK/TL/WA all present.

## Constraints (extracted from statement)

| variable | bound |
|---|---|
| t | 1 ≤ t ≤ 300 |
| n | 1 ≤ n ≤ 300 |
| sum of n over tests | ≤ 300 |
| m | 0 ≤ m ≤ n(n−1)/2 (per-test, depends on n) |
| k | 1 ≤ k ≤ 10^18 |

Multi-test input: yes. Output: permutation or −1; checker = exact int64-token compare (correct — answer is unique: k-th lexicographic permutation, or −1 iff fewer than k exist).

## Validator coverage gaps

`validator.cpp` checks: t∈[1,300], n∈[1,300], m∈[0,n(n−1)/2] (bound computed from the actual n), k∈[1,10^18] via readLong, cumulative sum n ≤ 300 with `ensuref`, strict single-space EOLN per line, readEof at end.
**No gaps.** Every statement bound is enforced.
Validator tests (8 registered, all run with expected verdicts): VALID sample, t=0, n=301, m>n(n−1)/2, k=0, k=10^18+1, sum-violation, junk-after-token. Complete.

## Generation script

`gen.cpp` modes: `sample1`, `sample2`, `edges 0..3`, `tiny 0..3`, `rand pattern(0..4) variant(0..2)`, `max 0..4`, `split 0..3`, `many`. Generator self-ensures t≤300 and sum n ≤300. Script = 34 fixed lines, deterministic coverage:
- `max 0..4`: single n=300 tests, m ∈ {mx/2, mx/3, 2mx/3, n, mx−n}, k ∈ {1, 999999999999999937, 10^18}.
- `split 0..3`: sum=300 split into 2/3/6/10 parts (n=150…30) — kills quadratic-per-test blowups and reset bugs.
- `many`: t=300 of n=1 (mixed k=1 and k=10^18 → existence and −1 at max t).
- `edges 0`: m=0 and m=max for all n=1..16; `edges 2`: {300, 0, 10^18}; `edges 3`: {299, mx, 1} + {1, 0, 10^18}.
- `rand`: m near 0 / near n / near max / near mx/2 / uniform, k styles {1, ≤1000, near-10^18, full-range}.

## Bound attainment (fetched tests 25, 26, 29, 32, 33, 34 — computed, not eyeballed)

| variable | stated bound | observed max | verdict |
|---|---|---|---|
| t | 300 | 300 (t34 `many`) | HIT |
| n | 300 | 300 (t25/t26/t29, all `max`) | HIT |
| sum n | 300 | 300 in every sampled file | HIT |
| k | 10^18 | 10^18 (t29, t34) | HIT |
| m (relative) | n(n−1)/2 | t29: n=300, m=44550 vs mx=44850 (99.3%); m=mx exactly only for n≤16 (`edges 0`) | near-HIT |
| k=1 | min | t26 (n=300, k=1) | HIT |
| m=0 | min | t32 case, edges 0/2 | HIT |

## Edge cases present

- n=1 (test 34 ×300, sample2 `{1,0,2}` → −1 since only 1 permutation), m=0, k=1, k=10^18
- m=0 / m=n(n−1)/2 for n=1..16 (`edges 0`); unique-permutation + k=2 → −1 (sample1 case 4)
- k == exact count boundary: sample1 `3 1 2` (count=2), `edges 1` includes n=3, m=1, k=2 (count=n−1=2) — off-by-one `<` vs `<=` is covered
- −1 at max scale: {300, 0, 10^18} and {1, 0, 10^18}
- 64-bit overflow traps: k=999999999999999937 (t25), near-10^18 k with astronomically large true counts at n=300 (capped DP + wide sliding-window sums exercised — exactly the bug the tutorial warns about)
- t=300 minimal-case file (I/O + reset bugs), sum-saturating split files

## Edge cases MISSING

1. **n=300 with m = n(n−1)/2 = 44850 exactly** (and k>1 → −1). Largest m at n=300 is 44550. Trivial combinatorially (count=1) but it is the literal corner of the m range at max n. Minor.
2. **Crafted k == dp[n][m] at large scale** (e.g. n=300, huge m-region where count is large; k set to exactly the count). Equality at boundary only verified on n=3. A random k has ~0 chance of hitting equality, so a wrong strict/loose comparison could survive large tests. Minor-to-moderate.
3. Anti-hardcode traps: N/A — this is a pure counting problem with dense random n/m/k sweeps; no index-skipping attack surface.

## TLE-killer analysis

Ontest t25 (n=300, m=22425): intended O(n·m) DP ≈ 6.7M ops ≪ TL. The natural slow approach (O(n²·m) table without sliding window) is ~2×10^9 ops ≈ 100x+ over budget — decisively dead. Any exponential/permutation-listing brute force dies by factors of 10^500+. `split` files (sum=300 over 6–10 tests) punish per-test O(n²·m) reset/alloc; `many` punishes per-test overhead. Honest brute force cannot pass: **no TLE-quality FAIL**.

## VERDICT: PASS

Validator airtight (all bounds + validator tests), every constraint bound is genuinely attained in fetched tests, near-10^18 k and capped-DP overflow paths exercised at n=300, split/many files cover aggregate bounds, verified package READY.

Concrete (optional) adds:
- `gen max 5`: `{{300, 44850, 2}}` — exact m-corner at max n, answer −1.
- `gen eqk`: one large case with k precomputed == dp[n][m] (e.g. n=200, m=mx−1, k = n) to pin the equality boundary at scale.
