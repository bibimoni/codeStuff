# Contest strategy — glm-5.3

## Status
ALL 12 PROBLEMS A-L SOLVED. Contest complete for glm-5.3.

## Per-problem status
| Letter | Status | Notes |
|--------|--------|-------|
| A | SOLVED | ans = 1 + #forced pairs; forced iff (b==n) or (a<n,b<n,pos[a+1]>pos[b+1]); never -1 for valid perm |
| B | SOLVED | GF(2): Gauss-Jordan on [A+I\|I] once (bitset<6008>), per query parity(T_j&b), -1 iff nonzero row beyond rank; free vars=0 |
| C | SOLVED | INTERACTIVE: L-walk finds h; binary search last level index, prefix-shared navigation; ~7000/8000 queries worst |
| D | SOLVED | UVa847: thresholds 9,18,162,324,...; t=9,stan=true; while n>t: t=stan?2t:9t, flip; n=1→premiere |
| E | SOLVED | KEY: sum over flex orientations = #LE(strict forest) (each perm ⊨strict counted once). #LE via labels: n!·∏∫G_root, G_v=∏child M_c, M=∫G or A−∫G; poly DP mod p, O(n²) worst |
| F | SOLVED | height with count exactly 7; print names in input order |
| B | unread | |
| C | unread | INTERACTIVE — flush stdout every line |
| D | unread | |
| E | unread | |
| F | unread | 8MB / 0.25s brutal limits |
| G | SOLVED | classic self-crossing (LC335): i vs i-3, i-4 touch, i-5 cases; stress-verified | |
| H | SOLVED | LRU+order: pb_ds tree on (pos,key), pos=n+i event idx; order = size - order_of_key; evict = begin() | |
| I | SOLVED | indep loops = E-V+C; reverse deletions w/ DSU, delta when re-adding = k - successes (k=alive reciprocal nbrs) | |
| J | SOLVED | S=0: 2^m (m=#zero prefixes, i<n). S!=0: candidates v=positive prefix vals dividing S, k=S/v<=n; DP over levels q*v (bail on empty level); f[q]+=f[q-1] at active pos sorted by idx | |
| K | SOLVED | free op: a_m:=max(a_l,a_r) reduces big middles. v(i)=min(a_i,max(pmin(i-1),smin(i+1))); pay 2 extreme zeros p,q (q-p>=k-1): v(p)+v(q); k=1: min v | |
| L | SOLVED | X_v=P_{v-1}+b_v, W_v=b_v-P_{v-1}; routes: arcs A/B; A+A: arcA+f(s,t) f=min_{u<v}(X_u+W_v); B+B: arcB+min(f(1,s-1),f(t+1,n),minW(B1)+minX(B2)-Pn); cross A-B: arcB-2Ps+minX(s,t-1)+min(minX(B1),minX(B2)-Pn); cross B-A: arcA+2Ps+min(minW(B1),minW(B2)+Pn)+minW(s+1,t); Nook dest: 4 terms. Lazy segtree {minX,minW,best} + BIT for P | |

## Log
- Start of run. Reading A first.
