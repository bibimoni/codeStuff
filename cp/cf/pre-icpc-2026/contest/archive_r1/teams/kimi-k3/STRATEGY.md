# kimi-k3 strategy — FINAL: 12/12 ALL SOLVED

Solved: A, B, C, D, E, F, G, H, I, J, K, L (all OK; B: 1 TL fail, J: ML+TL fails, rest first-try).

## Status (key insights)
- A (suffix-array): OK. Min distinct chars = 1 + #{i: rank[p_{i-1}+1] > rank[p_i+1]}, rank[n+1]=0. Never -1.
- B (grid-reboot): OK after optimizing naive (fix: TL on test 66 -> faster approach).
- C (the-hidden-cave, INTERACTIVE): OK. Complete binary tree = heap indexing. Walk L to find depth d (<=59); binary search largest existing index in last level, probe by toRoot + bit-walk. Worst ~7140 of 8000 queries.
- D (multiplication-game): OK. a=n; loop a=ceil(a/9)(even step)/ceil(a/2)(odd); stop a<=1; first wins iff even step.
- E (scheduling): OK. REDUCTION: answer = #lin-ext of fixed-edge forest (schedule forces flexible orientation). Tree DP f_v[j]; child q via prefix/suffix sums; binomial interleave; multinomial combine.
- F (snow-white): OK. Height with frequency exactly 7.
- G (self-crossing-turtle): OK. LeetCode 335 three conditions.
- H (rlu-cache): OK. Fenwick over touch counters; rank = n - (#alive counters < mine); evict via kth(1).
- I (coolant-loops): OK. "Independent loops" = circuit rank E - V + C. Reverse the deletions -> DSU insertions.
- J (equal-sum-segments): OK after rewrite. KEY: viable segment sum d must be a prefix value dividing S — iterate distinct prefix values, NOT divisors of S. Chain count per d via binary search over position lists. S==0 -> 2^(#zero prefixes).
- K (zero-segment): OK. Free op closure: paying l,r zeros whole interval => answer = min a_l + a_r with r-l >= k-1; k=1 -> min element.
- L (coral-loop): OK. Ring+hub shortest simple path. P prefix sums; X=b+P, Y=b-P segtree with (dx,dy) lazy; 2 ring arcs + 8 hub combo range queries (minX/minY/bestpair). a-update updP(+d,-d), b-update updB(+d,+d).

## Failed submissions (total 3)
- B: TL test 66 then OK.
- J: ML test 30, TL test 32, then OK (rewrote algorithm).

## BONUS
- M (k-th-inversion-permutation): OK. Mahonian count DP capped at 2e18. GOTCHA: sliding-window with saturation corrupts subtractions; fix = pin CAP once saturated in the increasing half (Mahonian unimodal+symmetric), mirror the rest. Greedy: at each pos pick c-th smallest remaining value costing c inversions, skip cnt[n-1][rem-c] blocks.
