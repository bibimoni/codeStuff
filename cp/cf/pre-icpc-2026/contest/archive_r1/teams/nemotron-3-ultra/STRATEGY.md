# Contest Strategy - nemotron-3-ultra

## Problem Overview

| Prob | Name | Difficulty | Status | Approach |
|------|------|------------|--------|----------|
| A | Suffix Array | Medium | ✅ | n≤50, construct string from SA |
| B | Grid Reboot | Hard | ✅ | GF(2) linear system, Gaussian elim with bitsets |
| C | The Hidden Cave | Medium | ✅ | Interactive, complete binary tree, binary search on depth |
| D | Multiplication Game | Easy | ✅ | Game theory, Stan wins if n in certain ranges |
| E | Scheduling | Hard | ✅ | Sum over orientations = linear extensions of fixed edges; tree DP O(n²) |
| F | Snow White | Trivial | ✅ | Count height frequencies, find height with freq=7 |
| G | Self-Crossing Turtle | Medium | ✅ | Check 3 patterns of self-crossing |
| H | RLU Cache | Medium | ✅ | Order statistic tree (PBDS) |
| I | Coolant Loops | Hard | ✅ | Reverse process (add junctions), DSU + cycle count |
| J | Equal Sum Segments | Medium | ✅ | Prefix sums, divisors of total sum |
| K | Zero Segment | Hard | ✅ | DP, free op means we can propagate zeros between paid positions |
| L | The Coral Loop | Hard | ✅ | Segment tree on cycle with 4 path configurations; range add/min queries |

## Solve Order (easiest first)

1. **F** - Snow White (trivial, 5 min)
2. **D** - Multiplication Game (classic, 10 min)
3. **A** - Suffix Array (small n, constructive, 20 min)
4. **J** - Equal Sum Segments (prefix sums, 20 min)
5. **G** - Self-Crossing Turtle (known patterns, 30 min)
6. **H** - RLU Cache (LRU with order, 40 min)
7. **C** - The Hidden Cave (interactive, binary tree, 45 min)
8. **B** - Grid Reboot (GF(2), 60 min)
9. **K** - Zero Segment (DP, 60 min)
10. **I** - Coolant Loops (reverse DSU, 60 min)
11. **E** - Scheduling (tree DP, 90 min)
12. **L** - The Coral Loop (segment tree, 90 min)

## Notes

- F has brutal limits: 0.25s, 8MB - use fast I/O, minimal memory
- C is INTERACTIVE - must flush after every query
- D outputs French phrases exactly
- Total time: ~5 hours