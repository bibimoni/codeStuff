# ICPC Contest Feedback — nemotron-3.5-lightning (Bonus Round Included)

## Problem Difficulty & Status

| Problem | Difficulty | Status | Tried / Blocker |
|---------|-----------|--------|-----------------|
| A | easy | solved | Suffix array minimum distinct characters; 103/103 passed |
| B | easy-medium | attempted | Fast path for invertible matrices (M^{-1} once + per-query vec). Singular case TL on test 8 with O(N^3/64) per-query Gaussian elimination |
| C | medium | attempted | Interactive: depth-finding going left from root, binary search for last level nodes. Navigation back to root via ? B queries after depth-finding. Large test cases have d=57 (not 26). |
| D | medium-hard | solved | Pattern: second player wins iff n=1 or n∈[9·18^(k-1)+1, 18^k]; output strings fixed from "gagne" to correct formula |
| E | medium-hard | attempted | Tree DP count valid schedules over edge orientations mod 998244353; n=5 example gives 10 (3+7); need sum over all flexible edge orientations |
| F | easy | solved | Find 7 men with same height from n men with heights 1..1000 |
| G | medium | solved | Turtle path self-intersection: check current segment against previous 5 segments using full geometric intersection (3 LeetCode 335 patterns gave false positives) |
| H | medium-hard | solved | RLU cache: BIT-based order maintenance with iterator tracking for O(1) LRU moves; 24/24 passed |
| I | medium | attempted | Cyclomatic number = E - V + C (edges - vertices + weakly connected components). Works for first test case output "1 0 0". Need dynamic connectivity after vertex removals. |
| J | medium-hard | attempted | Equal sum segments: product of cnt values doesn't ensure cut positions i_1 < i_2 < ... < i_{k-1} are in increasing order. Test 2 WA. |
| K | medium | untouched | Not started |
| L | hard | untouched | Not started |
| M | medium | solved | K-th inversion permutation: DP dp[n][m] = sum_{j=0}^{min(m,n-1)} dp[n-1][m-j], capped at 1e18+1. Construction: left-to-right, for each candidate v, inv_contrib = count of remaining values smaller than v; skip counts via dp table. 34/34 passed. |

## Judge Assessment

The local contest judge compiles with g++ -O2 -std=gnu++17, runs every test case, and verifies with problem testlib checkers. Each submission appends a JSON line to contest/results/<team>.jsonl with verdict (OK/WA/TL/ML/RE/CE/JE), first_fail test index, and timing. The contest clock showed ~173 minutes remaining at start, ending ~8 minutes before cutoff. Problem set had A (suffix-array, 1s/256MB), B (grid-reboot, 3s/512MB), C (the-hidden-cave, 2s/256MB INTERACTIVE), D (mulgame, 1s/256MB), E (scheduling, 2s/256MB), F (snow-white, 0.25s/8MB), G (self-crossing-turtle, 2s/256MB), H (rlu-cache-easy, 2s/256MB), I (coolant-loops, 2s/256MB), J (equal-sum-segments, 2s/256MB), K (zero-segment, 2s/256MB), L (coral-loop, 2s/256MB). Sum of N across all test cases ≤ 2·10^5, N ≤ 3000 per test case, Q ≤ 500 per test case. Bonus problem M added (300 total test cases sum n ≤ 300, m ≤ n(n-1)/2, k ≤ 1e18). The judge's test revelation API was not needed; local bruting sufficed for most problems.

## Summary

Solved 6/12: A(103/103), D(101/101), F(102/102), G(19/19), H(24/24), M(34/34). Attempted 5/12: B (singular TL), C (navigation), E (tree DP sum), I (dynamic loops), J (order-bug in cnt product). Untouched: K, L. Contest policy of spam-submitting allowed, stress-testing locally encouraged, and curl localhost:8777/api/state available for state checks after 20min stuck.

## Key Algorithms

- **Problem M** (bonus): dp[n][m] = number of permutations of {1..n} with exactly m inversions. Recurrence: dp[n][m] = sum_{j=0}^{min(m,n-1)} dp[n-1][m-j], computed with prefix-sum optimization and capping at 1e18+1. Construction: left-to-right placement, inv_contrib = count of remaining values smaller than candidate v, skip counts via dp table.

- **Problem D**: Second player wins iff n=1 or n∈[9·18^(k-1)+1, 18^k] for k=1,2,3,... where a_k=9·18^(k-1)+1, b_k=18^k.

- **Problem G**: Check current segment against previous 5 segments using full geometric intersection (orientation tests + on-segment checks), not just the 3 LeetCode 335 patterns.