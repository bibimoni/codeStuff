#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool join(int a, int b) {
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

    int t;
    cin >> t;
    const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1}, bit[] = {1, 2, 4, 8};
    while (t--) {
        int n, m;
        cin >> n >> m;
        int cells = n * m;
        vector<int> g(cells);
        for (int &x : g) cin >> x;
        int q;
        cin >> q;
        vector<int> hit(q);
        vector<bool> remaining(cells), alive(cells);
        for (int i = 0; i < cells; ++i) remaining[i] = g[i] != 0;
        for (int &x : hit) {
            int r, c;
            cin >> r >> c;
            x = (--r) * m + --c;
            remaining[x] = false;
        }
        DSU dsu(cells);
        long long cycles = 0;
        auto add = [&](int v) {
            alive[v] = true;
            int r = v / m, c = v % m;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int u = nr * m + nc;
                if (alive[u] && (g[v] & bit[k]) && (g[u] & bit[(k + 2) % 4]))
                    if (!dsu.join(v, u)) ++cycles;
            }
        };
        for (int v = 0; v < cells; ++v) if (remaining[v]) add(v);
        vector<long long> ans(q);
        for (int i = q - 1; i >= 0; --i) {
            ans[i] = cycles;
            add(hit[i]);
        }
        for (long long x : ans) cout << x << ' ';
        cout << '\n';
    }
}
