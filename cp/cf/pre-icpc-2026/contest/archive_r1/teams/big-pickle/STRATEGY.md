# STRATEGY — team big-pickle

Status legend: TODO / WIP / SUBMITTED / OK / FAILED

| P | Name | Status | Approach | Fails |
|---|------|--------|----------|-------|
| F | Snow White | OK | height occurring exactly 7 times | 0 |
| A | Suffix Array | OK | ans = 1 + #forced breaks; forced break at i iff r[p_i+1] > r[p_{i+1}+1], r[n+1]=0 | 0 |
| D | Multigame | OK | alternating intervals [1,9]W,[10,18]L,[19,162]W,... verify by brute | 0 |
| H | RLU Cache | OK | vector + LRU list; order = index in list from front | 2 |
| G | Self-Crossing Turtle | OK | spiral: check segment i vs i+1..3 | 1 |
| I | Coolant Loops | OK | DSU reverse order, edges from 0 to first non-loop merge | 3 |
| B | Grid Reboot | OK | GF(2) Gauss-Jordan on [A\|I] bitset, per-query solve | 0 |
| C | Hidden Cave (interactive) | OK | leftmost descent for height h, then binary search last level | 0 |
| K | Zero Segment | OK | k=1 -> min a_i; else min a_i+a_j, j-i>=k-1 (running prefix min) | 0 |
| J | Equal Sum Segments | OK | per divisor k of S: scan prefix positions, dp[pref[i]/(S/k)] += dp[. -1] | 0 |
| L | Coral Loop | OK | segtree over doubled a-array, 4-field node, 10 path shapes | 0 |
| E | Scheduling | OK | = # linear extensions of strict-edge poset (tree/forest), n<=4000 O(n^2) | 0 |

SOLVED: 12/12 (F,A,D,H,G,I,B,C,K,J,L,E). Penalty so far: 6 fails x 20 = 120 min.

## Details
- K: closure of paid set P is exactly [min P, max P] (a_m becomes 0 iff zeros at l<m<r).
  So cost = a_L+a_R for any L,R with R-L+1>=k. k=1 special (single pay).
- J: answer = # (perm, orientation) pairs = # perms respecting all STRICT edges
  (flexible edges have exactly 1 consistent orientation each) => 1 contribution per
  feasible perm. For each k|S: need cuts with prefix = j*S/k. Grid check first
  (skip k), then scan positions left->right: dp[j] += dp[j-1] (mod). S=0 => 2^(#zero-prefixes).
  Feasible k's are all multiples of the smallest => total DP work <= divcnt(kmax)*n.
- L: simple s->t path in a wheel = cycle-only (2 arcs) or uses the Nook once:
  s ->[arc] x ->(b_x) Nook ->(b_y) y ->[arc] t. 9 arc combinations (up/down each side),
  disjointness forces the arc pair, so exactly 10 candidates, each a range aggregate.
  Doubled array (2n leaves), Pp(i)=prefix before i, Up_i=b_i-Pp(i), Vp_i=b_i+Pp(i);
  node keeps sum, minUp, minVp, ord=min_{i<j}(Vp_i+Up_j), all relative to node start
  (merge shifts right side by -/+L.sum). Both arc1 (up) and arc2 (down) reuse ord.
  Nook query: min(b_s, minVp+a_s, minUp+sum(arc)) over arc=[s+1,s+n-1].
  Verified vs DFS brute on ~2000 random cases + edge sweeps (adjacent, wrap, n=2).
Started t=1790457161. Ends t=1790475161.

## Notes
- A: every permutation IS a valid SA; minimum distinct chars = 1 + number of forced
  strict increases. Proven by induction on suffix length. -1 never needed.
- F: unique height with count 7.
