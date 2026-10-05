# glm-5.3 contest strategy — FINAL

## FINAL STATUS: ALL 13 SOLVED (A–M). feedback.md written.
Solved order: D,F,K,A (first batch) → H,J,I,M (after local stress) → B,C → G → E → L.
Total: 13 problems, judge verdicts all OK.

## Per-problem one-liners (see feedback.md for detail)
- A: min-alphabet from SA, greedy classes + verify (stressed exhaustively n<=6).
- B: GF2 RREF [M|I]->[R|L] once, O(N^2/64)/query.
- C: interactive; spine probe d, binsearch last level, ~7200 queries max (mock: 7062).
- D: win-intervals ladder *2/*9; French strings.
- E: answer = Le of forced-edge forest (flexible = free choice bijection); cut-decomposition DP with L/R prefix-cumulative arrays + child polynomial convolution, O(n^2). Brute-stressed n<=7,9.
- F: height w/ exactly 7 entries.
- G: axis-aligned sweep HxH/VxV + HxV with multiset, skip 2 adjacent ids.
- H: Fenwick on timestamp slots; rank = size - prefix + 1. (TL fix: proportional unordered_map reserve!)
- I: reverse-time DSU; loops = E - V + C. (bug fixed: edge added at later endpoint's insertion only)
- J: S=0 => 2^z; else per divisor k<=n of S: stepTotal DP (mod inline!)
- K: 2 anchors span >= k-1 zero whole window free; k=1 min element.
- L: 4 route shapes; paired-segtree (mnA,mnB,prAB) + range-add lazy; Fenwick C-prefixes. Stressed n<=8 vs multigraph DFS brute, 550 cases.
- M: capped Mahonian sliding window (u128), reconstruct by rank; output WITH spaces.

## Lessons (for a rerun)
- Mod during accumulation, not after (J).
- Output separators (M).
- Per-test allocations must scale with test size, not fixed constants (H TL with t up to 2e5 tests).
- Reduce-derived submissions took 2 tries max; every failure was mechanical, caught by judge + fixed in minutes.
