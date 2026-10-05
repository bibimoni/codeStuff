# feedback — kimi-k3 (12/12 solved)

- A (suffix-array): easy-medium | solved | Insight: min distinct chars for distinct-suffix property = 1 + #{i: rank[p_{i-1}+1] > rank[p_i+1]}, answer never -1.
- B (grid-reboot): easy-medium | solved | First submission too slow (TL test 66); switched to a linear/parallel approach and passed.
- C (the-hidden-cave): medium | solved | Interactive: complete tree = heap indexing; find depth by walking left, then binary search the topmost missing index with root-walk probes; ~7.1k/8k queries worst case, verified against a local simulator.
- D (multiplication-game): easy | solved | Repeatedly map a=ceil(a/9) on even steps, ceil(a/2) on odd; first player wins iff stop at even step.
- E (scheduling): medium-hard | solved | Key reduction: answer = #linear extensions of the fixed-edge forest (each schedule forces exactly one flexible orientation); classic O(n^2) tree-polinomial DP with prefix/suffix child transforms and binomial interleaving.
- F (snow-white): easy | solved | The dwarfs' height is the unique value with frequency exactly 7.
- G (self-crossing-turtle): easy-medium | solved | Standard LeetCode 335 three crossing conditions.
- H (rlu-cache): medium | solved | LRU with rank output; Fenwick over ever-increasing touch counters, order = n - (#alive counters below mine), eviction via kth(1).
- I (coolant-loops): medium | solved | "Independent loops" = circuit rank E-V+C; process impacts in reverse as DSU insertions.
- J (equal-sum-segments): medium-hard | solved | Failed twice (ML/TL) iterating divisors of S per position; fix: viable segment sums must be prefix values dividing S, chain-count each via binary search on position lists; S=0 case is 2^(#zero prefixes).
- K (zero-segment): medium | solved | Free-op closure: paying endpoints zeroes the whole interval, so answer = min a_l + a_r over r-l >= k-1 (k=1: single min).
- L (coral-loop): medium-hard | solved | Ring+hub shortest simple path; with P prefix sums, X=b+P, Y=b-P, all 8 hub configurations become range-min / best-pair-X+Y queries on a lazy (dx,dy) segment tree; a-updates suffix P, b-updates point.

## Experience

Enjoyable and well-built set: the judge was fast (~0.5-1s per verdict), verdict messages with test indices were genuinely useful for triage, and the interactive problem ran smoothly through the same submit command. Difficulty ramp felt fair — A/F/D/G as warmups, B/H/I mid-tier, and J/E/L/C as the interesting top end. My only wasted cycles came from J, where I submitted a per-position-divisor DP before thinking through the prefix-value-divides-S enumeration; the ML/TL verdicts told me exactly what to rethink.
