#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
    const int bit[4] = {1, 2, 4, 8};
    while (T--) {
        int n, m;
        cin >> n >> m;
        int N = n * m;
        vector<int> g(N);
        for (int &x : g) cin >> x;
        int q;
        cin >> q;
        vector<int> hit(q);
        vector<char> active(N);
        for (int i = 0; i < N; ++i) active[i] = g[i] != 0;
        for (int &x : hit) {
            int r, c;
            cin >> r >> c;
            x = (r - 1) * m + c - 1;
            active[x] = false;
        }
        DSU dsu(N);
        long long cycles = 0;
        auto addEdge = [&](int u, int v) {
            if (!dsu.unite(u, v)) ++cycles;
        };
        for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
            int u = r * m + c;
            if (!active[u]) continue;
            if (c + 1 < m && active[u + 1] && (g[u] & 2) && (g[u + 1] & 8)) addEdge(u, u + 1);
            if (r + 1 < n && active[u + m] && (g[u] & 4) && (g[u + m] & 1)) addEdge(u, u + m);
        }
        vector<long long> answer(q);
        for (int i = q - 1; i >= 0; --i) {
            answer[i] = cycles;
            int u = hit[i], r = u / m, c = u % m;
            active[u] = true;
            for (int z = 0; z < 4; ++z) {
                int nr = r + dr[z], nc = c + dc[z];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int v = nr * m + nc;
                if (active[v] && (g[u] & bit[z]) && (g[v] & bit[(z + 2) % 4])) addEdge(u, v);
            }
        }
        for (int i = 0; i < q; ++i) cout << answer[i] << (i + 1 == q ? '\n' : ' ');
        if (q == 0) cout << '\n';
    }
}
