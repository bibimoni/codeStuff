#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p;
    DSU(int n) : p(n, -1) {}
    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool merge(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (p[a] > p[b]) swap(a, b);
        p[a] += p[b]; p[b] = a;
        return true;
    }
};
int main() {
    int t; if (scanf("%d", &t) != 1) return 0;
    string out;
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        int N = n * m;
        vector<int> g(N);
        for (int i = 0; i < N; i++) scanf("%d", &g[i]);
        int q; scanf("%d", &q);
        vector<int> hit(q);
        vector<char> dead(N, 0);
        for (int i = 0; i < q; i++) {
            int r, c; scanf("%d %d", &r, &c);
            hit[i] = (r - 1) * m + (c - 1);
            dead[hit[i]] = 1;
        }
        DSU dsu(N);
        long long V = 0, E = 0, C = 0;
        for (int i = 0; i < N; i++) {
            if (!g[i] || dead[i]) continue;
            V++; C++;
            int r = i / m, c = i % m;
            if (c + 1 < m && !dead[i + 1] && g[i + 1] && (g[i] & 2) && (g[i + 1] & 8)) {
                E++; if (dsu.merge(i, i + 1)) C--;
            }
            if (r + 1 < n && !dead[i + m] && g[i + m] && (g[i] & 4) && (g[i + m] & 1)) {
                E++; if (dsu.merge(i, i + m)) C--;
            }
        }
        vector<long long> ans(q);
        if (q > 0) ans[q - 1] = E - V + C;
        for (int i = q - 2; i >= 0; i--) {
            int u = hit[i + 1];
            V++; C++;
            int r = u / m, c = u % m;
            if (c > 0 && !dead[u - 1] && g[u - 1] && (g[u] & 8) && (g[u - 1] & 2)) { E++; if (dsu.merge(u, u - 1)) C--; }
            if (c + 1 < m && !dead[u + 1] && g[u + 1] && (g[u] & 2) && (g[u + 1] & 8)) { E++; if (dsu.merge(u, u + 1)) C--; }
            if (r > 0 && !dead[u - m] && g[u - m] && (g[u] & 1) && (g[u - m] & 4)) { E++; if (dsu.merge(u, u - m)) C--; }
            if (r + 1 < n && !dead[u + m] && g[u + m] && (g[u] & 4) && (g[u + m] & 1)) { E++; if (dsu.merge(u, u + m)) C--; }
            dead[u] = 0;
            ans[i] = E - V + C;
        }
        for (int i = 0; i < q; i++) { if (i) out += ' '; out += to_string(ans[i]); }
        out += '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
