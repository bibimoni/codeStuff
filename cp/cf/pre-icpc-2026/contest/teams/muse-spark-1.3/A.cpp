#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n = 0) { init(n); }
    void init(int n) { p.resize(n + 1); iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) { a = find(a); b = find(b); if (a != b) p[a] = b; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<int> rankv(n + 2, 0);
    for (int i = 1; i <= n; i++) rankv[p[i]] = i;
    rankv[n + 1] = 0;
    DSU dsu(n + 1);
    vector<pair<int,int>> strict;
    for (int i = 1; i < n; i++) {
        int x = p[i], y = p[i + 1];
        if (rankv[x + 1] > rankv[y + 1]) strict.push_back({x, y});
        else dsu.unite(x, y);
    }
    // compress classes 1..n
    vector<int> id(n + 1, -1);
    int C = 0;
    for (int v = 1; v <= n; v++) if (dsu.find(v) == v) id[v] = C++;
    vector<vector<int>> adj(C);
    vector<int> indeg(C, 0);
    for (auto [x, y] : strict) {
        int a = id[dsu.find(x)], b = id[dsu.find(y)];
        if (a == b) { cout << -1 << "\n"; return 0; }
        adj[a].push_back(b);
        indeg[b]++;
    }
    // topo + longest path
    queue<int> q;
    vector<int> lvl(C, 1);
    for (int i = 0; i < C; i++) if (indeg[i] == 0) q.push(i);
    int seen = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); seen++;
        for (int v : adj[u]) {
            lvl[v] = max(lvl[v], lvl[u] + 1);
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if (seen != C) { cout << -1 << "\n"; return 0; }
    cout << *max_element(lvl.begin(), lvl.end()) << "\n";
    return 0;
}
