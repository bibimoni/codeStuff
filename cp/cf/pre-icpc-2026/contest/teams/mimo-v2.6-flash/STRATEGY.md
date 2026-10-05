# STRATEGY (mimo-v2.6-flash)

## Status (12 OK: F D H M J G A I B K L C)
- **F, D, H, M, J, G, A, I, B, K, L, C: OK** — all verified locally (brutes) then judged.
- K: min pair a_L+a_R, R-L+1>=k (brute vs Dijkstra 400). L: 8-topology min simple path, segtree (minCX/minDY/pairmin) + suffix lazy (a-upd: +d/-d, b-upd: +d/+d), brute vs DFS 1228 queries. C: binary search on heap-index existence with LCA-reuse walk, ~3700/8000 queries.
- Remaining: E (LE of tree-cover poset — deep analysis below).

## E notes (LE of tree-cover poset)
Answer = #linear extensions of poset from fixed edges only (bijection: each valid (orientation, schedule) <-> schedule, orientation forced).
Derivation: for subtree T_v (tree rooted), LE(T_v) = interleavings of child LEs with constraint L_v < D_v (all pairs), where L_v = nodes reaching v = {v} ∪ ⋃_{c: c→v} L_c, D_v = {v} ∪ ⋃_{c: v→c} D_c. Each child contributes L-elements OR D-elements (never both) at parent level.
Merge of 2 seqs with "all X of seq1 before all Y of seq2" where X = suffix-ish ideal: constraint ⟺ (last X of seq1) before (first Y of seq2); count depends only on (m, n, idx_lastX, idx_firstY): paths count = Σ_{e=0}^{i-1} C(e+j-1,e)·C(m-e+n-j, m-e).
State for subtree: (size, lastL pos, firstD pos) — needs joint distribution; O(s^2) states maybe. UNRESOLVED: exact efficient DP. Next idea: maybe only (lastL, firstD) matters and transitions can be convolved; or maybe track only "position of last L" for A-exposure and "position of first D" for B-exposure separately with 1D profiles each (since parent needs only ONE of them depending on edge orientation). Investigate: dpA_v[i] = #LEs of T_v where last element of L_v is at position i; dpB_v[j] = #LEs where first element of D_v at j. For parent merging with sibling subtrees, need joint? Check.

## Order of attack
F done -> D, H, J, M, G, I, B, A, then C/E/L.
