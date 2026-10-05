given a graph with n + 1 (n <= 3e5) vertices, a[i] denotes there is an edge from i to (i mod n) + 1 with weight a[i]
also there are an edge from i (1 <= i <= n) to n + 1 with weight b[i]

all edges are bidirectional

(-1e9 <= a[i], b[i] <= 1e9)

given q (q <= 3e5) queries 
type 1: 
    return shortest path from s to t (1 <= s < t <= n + 1)
type 2:
    given i, w set a[i] to w
type 3: 
    given i, w set b[i] to w
