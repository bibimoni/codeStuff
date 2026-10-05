#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { while (p[x] != x) { p[x] = p[p[x]]; x = p[x]; } return x; }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        int N = n * m;
        vector<int> g(N);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &g[i * m + j]);
        int q; scanf("%d", &q);
        vector<int> hit(q);
        vector<char> dead(N, 0);
        for (int i = 0; i < q; i++) {
            int r, c; scanf("%d %d", &r, &c);
            hit[i] = (r - 1) * m + (c - 1);
            dead[hit[i]] = 1;
        }
        auto live = [&](int id) { return g[id] != 0 && !dead[id]; };
        // count edges: right and down neighbors
        auto edgeCount = [&](int id) {
            int cnt = 0, i = id / m, j = id % m;
            if (j + 1 < m) { int v = id + 1; if (live(id) && live(v) && (g[id] & 2) && (g[v] & 8)) cnt++; }
            if (i + 1 < n) { int v = id + m; if (live(id) && live(v) && (g[id] & 4) && (g[v] & 1)) cnt++; }
            return cnt;
        };
        DSU dsu(N);
        long long V = 0, E = 0, succ = 0;
        for (int id = 0; id < N; id++) if (live(id)) {
            V++;
            int i = id / m, j = id % m;
            if (j + 1 < m) { int v = id + 1; if (live(v) && (g[id] & 2) && (g[v] & 8)) { E++; if (dsu.unite(id, v)) succ++; } }
            if (i + 1 < n) { int v = id + m; if (live(v) && (g[id] & 4) && (g[v] & 1)) { E++; if (dsu.unite(id, v)) succ++; } }
        }
        long long C = V - succ;
        vector<long long> ans(q + 1);
        ans[q] = E - V + C; fprintf(stderr, "init V=%lld E=%lld C=%lld loops=%lld\n", V, E, C, ans[q]);
        // restore in reverse
        for (int i = q - 1; i >= 0; i--) {
            int id = hit[i];
            dead[id] = 0;
            V++;
            int r = id / m, c = id % m;
            vector<int> roots;
            int nb[4][4] = {{-1, 0, 1, 4}, {0, 1, 2, 8}, {1, 0, 4, 1}, {0, -1, 8, 2}};
            for (int d = 0; d < 4; d++) {
                int nr = r + nb[d][0], nc = c + nb[d][1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int v = nr * m + nc;
                if (g[v] == 0 || dead[v]) continue;
                if (!(g[id] & nb[d][2])) continue;
                if (!(g[v] & nb[d][3])) continue;
                E++;
                int rt = dsu.find(v);
                bool dup = false;
                for (int x : roots) if (x == rt) dup = true;
                if (!dup) roots.push_back(rt);
            }
            for (int k = 0; k < (int)roots.size(); k++) dsu.unite(id, roots[k]);
            C += 1 - (int)roots.size();
            ans[i] = E - V + C; fprintf(stderr, "restore %d id=%d V=%lld E=%lld C=%lld k=%zu loops=%lld\n", i, id, V, E, C, roots.size(), ans[i]);
        }
        for (int i = 1; i <= q; i++) printf("%lld%c", ans[i], i == q ? '\n' : ' ');
        if (q == 0) printf("\n");
    }
    return 0;
}
