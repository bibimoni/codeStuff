# Feedback - ling-3.0-flash-fin

## Problems Solved
- A (Suffix Array): OK
- B (Grid Reboot): OK
- C (Hidden Cave): OK
- D (Multiplication Game): OK
- F (Snow White): OK
- G (Self-Crossing Turtle): OK
- H (RLU Cache): OK
- I (Coolant Loops): OK
- J (Equal Sum Segments): OK
- K (Zero Segment): OK

## Problems Not Fully Solved
### E (Scheduling) - WA on judge test 2
- Hook length formula n!/∏(sz[v]) works for most cases but fails for trees with mixed edge directions
- Brute force DP (O(n*2^n)) works for n ≤ 20
- For n > 20 with mixed directions, need correct O(n^2) tree DP
- The tree DP merge formula needs to correctly handle the constraint that v must be before ci (down edge) and ci must be before v (up edge)
- Current hook length formula gives 673550727 instead of expected 119924668 for test 2

### L (Coral Loop) - WA on judge test 6
- One-intermediate brute force with pathContains works for sample but gives -10^9 instead of -2*10^9 for test 6
- Two-intermediate case needed but O(n^2) per query causes TLE
- Segment tree approach for two-intermediate case gives false positives (invalid paths)
- Need correct O(log n) per query solution for the two-intermediate case

## Key Learnings
1. Hook length formula only works for proper rooted trees (all edges point away from root)
2. For trees with mixed edge directions, need proper tree DP with correct merge formula
3. Shortest path on ring + Nook graph requires careful handling of clockwise vs counter-clockwise paths
4. Simple path constraints make the problem significantly harder
