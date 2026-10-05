# Feedback (mimo-v2.6-flash)

- A (Archive of Lost Letters): medium | solved | suffix-array constraints (strict iff pos[a+1] >= pos[b+1]), longest strict path with cycle check; verified vs brute (303 cases).
- B (Blackout on the Neural Grid): medium | solved | GF(2) bitset REF once + query transforms; single-test input gotcha (no t line), brute-verified.
- C (Cave of Countless Chambers): medium | solved | interactive binary search on heap-index existence with LCA-reuse walk, ~3700/8000 queries.
- D (Duel of the Twin Sisters): easy-medium | solved | bitsets over 7-smooth sieve, S=5194.
- E (Engineer's Schedule): medium-hard | attempted | reduced to counting LEs of the fixed-edge tree poset (clean bijection, sample matches), but no correct poly DP before time ran out; never submitted.
- F (Fairest of Them All): easy | solved | first blood for me, straightforward.
- G (Gardener's Turtle): easy-medium | solved | four HV/H-H/V-V sweep passes.
- H (Humble RLU Cache): easy-medium | solved | Fenwick-based LRU simulation.
- I (Impact on Polaris Deep): easy-medium | solved | cycle rank via reverse DSU over impacts, brute-verified.
- J (Jeweler's Fair Cuts): easy-medium | solved | split DP.
- K (Karesansui Garden): medium | solved | min over L of a[L] + suff[L+k-1]; partial payments useless; brute vs Dijkstra.
- L (Luminous Coral Loop): medium | solved | 8-topology min simple path with segment tree + dual lazy; three bugs found via brute before judging.
- M (Marshal's Parade): easy-medium | solved | inversion-count DP + lex greedy.

Judge was reliable: every accepted submission had already survived a local brute-force differential test, so no wasted runs or judge quirks; the interactive judge for C behaved exactly like my local simulator. Problem set was well balanced with a clean difficulty ramp — the only complaint is that E's jump from "spot the bijection" to "count LEs of a mixed-orientation tree poset" is a cliff that 12/13 of my time couldn't get past.
