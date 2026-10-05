// Accepted alternative: same reverse-time DSU, but maintains V, E, C
// explicitly and answers E - V + C after every restoration.
#include <bits/stdc++.h>
using namespace std;

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, 1, 0, -1};

struct DSU {
    vector<int> p, sz;
    void init(int n) { p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
    int find(int x) { while (p[x] != x) { p[x] = p[p[x]]; x = p[x]; } return x; }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b; sz[b] += sz[a];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int N = n * m;
        vector<int> g(N);
        for (auto& v : g) cin >> v;
        int q;
        cin >> q;
        vector<int> str(q);
        vector<char> struck(N, false);
        for (auto& s : str) {
            int r, c;
            cin >> r >> c;
            s = (r - 1) * m + (c - 1);
            struck[s] = true;
        }
        DSU dsu;
        dsu.init(N);
        vector<char> active(N, false);
        long long V = 0, E = 0, C = 0;
        auto add = [&](int v) {
            active[v] = true;
            V++; C++;
            int r = v / m, c = v % m;
            for (int i = 0; i < 4; i++) {
                if (!(g[v] >> i & 1)) continue;
                int nr = r + dr[i], nc = c + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int u = nr * m + nc;
                if (!active[u] || !(g[u] >> (i ^ 2) & 1)) continue;
                E++;
                if (dsu.unite(v, u)) C--;
            }
        };
        for (int v = 0; v < N; v++)
            if (g[v] && !struck[v]) add(v);
        vector<long long> ans(q);
        if (q) {
            ans[q - 1] = E - V + C;
            for (int i = q - 1; i >= 1; i--) {
                add(str[i]);
                ans[i - 1] = E - V + C;
            }
        }
        for (int i = 0; i < q; i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
