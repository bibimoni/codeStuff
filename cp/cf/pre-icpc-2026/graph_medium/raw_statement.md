Given an m × n grid, each cell is empty or contains a pipe. A pipe has openings in 2, 3, or 4 of the directions up, down, left, and right, giving 6 + 4 + 1 = 11 pipe types. Two adjacent pipes are connected when their openings face each other. Pipes are destroyed one by one. After each destruction, find the number of independent loops remaining in the network. (mn, q <= 2 * 10^5)

Below are the presentation of the pipes, each 3x3 block translates into 1 cell in the grid above
```
2 openings:

 UD      LR      UR      UL      DR      DL
.|.     ...     .|.     .|.     ...     ...
.+.     -+-     .+-     -+.     .+-     -+.
.|.     ...     ...     ...     .|.     .|.


3 openings:

 URD     ULD     ULR     LRD
.|.     .|.     .|.     ...
.+-     -+.     -+-     -+-
.|.     .|.     ...     .|.


4 openings:

 ULRD
.|.
-+-
.|.```

testcase: don't have

Solution: Process destructions in reverse, adding pipes back with DSU and connecting them to active neighboring pipes.
Maintain active vertices V, connections E, and components C; after each step, the number of independent loops is E - V + C.
