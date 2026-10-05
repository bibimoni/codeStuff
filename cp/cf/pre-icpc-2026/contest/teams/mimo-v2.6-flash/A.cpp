#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    vector<int> p(n + 1), pos(n + 2);
    for (int i = 0; i < n; i++) { scanf("%d", &p[i]); }
    for (int i = 0; i < n; i++) pos[p[i]] = i;
    pos[n + 1] = -1; // empty suffix
    // edges along the path p[i] -> p[i+1]
    struct Edge { int u, v, w; };
    vector<Edge> edges;
    for (int i = 0; i < n - 1; i++) {
        int a = p[i], b = p[i + 1];
        int c1 = (a + 1 <= n) ? pos[a + 1] : -1;
        int c2 = (b + 1 <= n) ? pos[b + 1] : -1;
        int strict = (c1 >= c2) ? 1 : 0;
        edges.push_back({a, b, strict});
    }
    // reachability (edges form a path, so no cycles, but check anyway)
    vector<vector<char>> reach(n + 1, vector<char>(n + 1, 0));
    for (auto& e : edges) reach[e.u][e.v] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            if (reach[i][k])
                for (int j = 1; j <= n; j++)
                    if (reach[k][j]) reach[i][j] = 1;
    for (auto& e : edges)
        if (e.w && reach[e.v][e.u]) { puts("-1"); return 0; }
    // longest strict path
    vector<int> d(n + 1, 0);
    for (int it = 0; it < n; it++) {
        bool changed = false;
        for (auto& e : edges) {
            if (d[e.u] + e.w > d[e.v]) { d[e.v] = d[e.u] + e.w; changed = true; }
        }
        if (!changed) break;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, d[i]);
    printf("%d\n", mx + 1);
    return 0;
}
