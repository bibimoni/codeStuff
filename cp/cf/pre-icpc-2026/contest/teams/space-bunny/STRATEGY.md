# space-bunny STRATEGY (5h ICPC, 13 problems A..M) — FINAL: 13/13 OK, rank 4/13, penalty 308

## Status board (all SOLVED)
| L | slug | status | approach | stress-tested? |
|---|------|--------|----------|----------------|
| A | suffix-array | **OK** @29m | ans = 1 + #{i : rk[p_i+1] > rk[p_{i+1}+1]} | all perms n<=6 vs brute force |
| B | grid-reboot | **OK** @34m | GF(2) fwd elim on [A\|I] bitsets, c=T·b, back-subst | 300 random vs brute |
| C | the-hidden-cave | **OK** @30m | interactive: bsearch level h (path=all-L), then bsearch pos m; LCA path nav | mock interactor, 25 sizes, max 3658/8000 queries |
| D | mulgame | **OK** @6m | losing n in (hi,2hi] with hi*=18 from 9 | 7-smooth DP, n=2..3000 + 300 random |
| E | scheduling | **OK** @27m | tree-poset linear extensions: shuffle DP over tree, f[v]=gB*gA | 400 random vs orientation-sum brute |
| F | snow-white | **OK** @2m | mode of heights, print in input order | sample |
| G | self-crossing-turtle | **OK** @18m | sweep-line perp + parallel overlap by same x/y | 400 random vs O(n^2) |
| H | rlu-cache-easy | **OK** @17m | LRU doubly-linked list + Fenwick over access ts | 300 cases vs naive list |
| I | coolant-loops | **OK** @17m | loops = E-V+C, reverse DSU over destroyed tiles | sample + manual traces |
| J | dp-math-hard | **OK** @36m | S=0 -> 2^zeros; else per divisor v: layer chain-DP | 500 random vs subset brute |
| K | zero-segment | **OK** @6m | min_j (a_j + prefixmin[j-k+1]) | sample + proof of 2-zero support |
| L | coral-loop | **OK** @47m | 4 path cases, lazy segtree on doubled array (minF,minG,P1) | ~2000 queries vs DFS brute |
| M | dp-counting-med | **OK** @19m (1 WA) | Mahonian DP (__int128!), greedy by candidate | 560 random vs permutation brute |

## Key formulas
- **A**: 0-index p, rk[n] = -1. chars equal allowed iff rk[p_i+1] < rk[p_{i+1}+1]; min distinct
  = 1 + #forced splits. -1 is UNREACHABLE (proved: greedy always yields a valid string).
- **D**: first player wins iff n<=9 or n in (18,162],(324,2916],(5832,52488],(104976,944784],
  (1889568,17006112],(34012224,306110016],(612220032,5.5e9]. hi starts 9, next hi = 18*hi.
- **E**: answer = #permutations respecting FIXED edges only (each valid (perm,orientation) pair
  is unique per perm). Count = tree-poset linear extensions: root forest, for node v split
  children into before/after; f[v] = gB*gA (no binomial factor - v's position is forced).
  Merge over components with C(processed+size, size).
- **H**: order r = 1 + #{live keys with ts > ts[key]}; ts(key i) starts at i (NOT n-i+1).
- **I**: loops = E - V + C. On adding a vertex with k distinct neighbour comps: C += 1-k,
  and the new vertex must itself be unioned with them (dsu.unite(id, root) for each).
- **J**: S!=0, sign-normalise; for each divisor v of S with v<=S/2 appearing as a prefix sum,
  require all of v,2v,...,(g-1)v present, then chain-DP over layers of positions (mod).
- **L**: (doubled array, SS[i]=prefix, F=SS+b, G=b-SS, P1=min over i<j of F(i)+G(j))
  island-island answer = min of 6 terms: 2 cycle arcs, and hub cases
  (i) ST-SS+P1[s,t]  (ii) minF[s,t-1]+minF[t+1,s+n-1]-SS-ST
  (iii) SS(s+n)+ST+minG[t+1,s+n-1]+minG[s+1,t]  (iv) SS(s+n)-ST+P1[t+1,s+n-1].
  Nook: min( minF[s,s+n-1]-SS[s], SS[s+n]+minG[s+1,s+n-1] ).

## Gotchas that cost me time (do not repeat)
- Linked list: after unlinking the TAIL, `tail==-1` does NOT mean the list is empty -> check head.
- Range query for pair aggregates must MERGE pieces in order (min of pieces misses cross pairs).
- Lazy tag for a stored value -G must use -(db-ds), not (db-ds).
- Doubled array: a_x occurs at positions x and x+n -> its SS suffix update must be applied TWICE.
- Fenwick/segment word alignment: the T part of [A|I] must start on a word boundary.
- int64 overflow in a prefix-sum DP (Mahonian): use __int128 for the running sum, cap on store.
- Multi-test stdout buffers must be reset per test case.
- Outputting ans[i] vs ans[i+1] in the reverse-DSU problem: answers are "after i impacts".

## Harness (reusable)
- `samp.py <LETTER> <exe>`: extract samples from problems/<L>.txt, diff (whitespace-tolerant).
- brute_{d,h,g,b,l2,l3}.py / brute_{e,j}.py: random generators vs brute force.
- `mock.py`: mock interactor for C (query accounting + verdict).
- NOTE: judge input may space-separate bit strings (problem B sample) -> read chars with " %c".
