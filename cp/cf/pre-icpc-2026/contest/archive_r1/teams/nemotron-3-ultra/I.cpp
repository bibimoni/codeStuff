#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n = 0) { init(n); }
    void init(int n) { p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
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
    int T; cin >> T;
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
    const int bit[4] = {1, 2, 4, 8};
    while (T--) {
        int n, m; cin >> n >> m;
        int N = n * m;
        vector<int> g(N);
        for (int i = 0; i < N; ++i) cin >> g[i];
        int q; cin >> q;
        vector<int> qr(q), qc(q);
        vector<char> alive(N, 1);
        for (int i = 0; i < q; ++i) {
            int r, c; cin >> r >> c; --r; --c;
            qr[i] = r; qc[i] = c;
            alive[r * m + c] = 0;
        }
        DSU dsu; dsu.init(N);
        int loops = 0;
        auto idx = [&](int r, int c) { return r * m + c; };

        // Initial build: state after ALL q impacts. Count each edge exactly once.
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < m; ++c) {
                if (!alive[r * m + c] || g[r * m + c] == 0) continue;
                int u = r * m + c;
                for (int d = 0; d < 4; ++d) {
                    if (!(g[u] & bit[d])) continue;
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    int v = nr * m + nc;
                    if (v <= u) continue;              // dedupe: count each edge once
                    if (!alive[v] || g[v] == 0 || !(g[v] & bit[d ^ 2])) continue;
                    if (!dsu.unite(u, v)) ++loops;
                }
            }

        vector<int> ans(q);
        for (int i = q - 1; i >= 0; --i) {
            ans[i] = loops;
            int r = qr[i], c = qc[i];
            alive[r * m + c] = 1;
            int u = r * m + c;
            for (int d = 0; d < 4; ++d) {
                if (!(g[u] & bit[d])) continue;
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int v = nr * m + nc;
                if (alive[v] && g[v] && (g[v] & bit[d ^ 2])) {
                    if (!dsu.unite(u, v)) ++loops;
                }
            }
        }
        for (int i = 0; i < q; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}