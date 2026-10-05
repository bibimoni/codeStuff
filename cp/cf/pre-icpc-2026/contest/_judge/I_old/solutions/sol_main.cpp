// Model solution: process impacts in reverse, restoring junctions with DSU.
// Track the loop count directly: adding a vertex or a component-merging edge
// never changes it; an edge whose endpoints are already connected adds one.
#include <bits/stdc++.h>
using namespace std;

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, 1, 0, -1}; // bit i (value 1<<i): U R D L

struct DSU {
    vector<int> p;
    void init(int n) { p.resize(n); iota(p.begin(), p.end(), 0); }
    int find(int x) { while (p[x] != x) { p[x] = p[p[x]]; x = p[x]; } return x; }
    // returns false if already united
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        p[a] = b;
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
        long long loops = 0;
        auto add = [&](int v) {
            active[v] = true;
            int r = v / m, c = v % m;
            for (int i = 0; i < 4; i++) {
                if (!(g[v] >> i & 1)) continue;
                int nr = r + dr[i], nc = c + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int u = nr * m + nc;
                if (!active[u] || !(g[u] >> (i ^ 2) & 1)) continue;
                if (!dsu.unite(v, u)) loops++;
            }
        };
        for (int v = 0; v < N; v++)
            if (g[v] && !struck[v]) add(v);
        vector<long long> ans(q);
        if (q) {
            ans[q - 1] = loops;
            for (int i = q - 1; i >= 1; i--) {
                add(str[i]);
                ans[i - 1] = loops;
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
