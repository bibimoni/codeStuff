#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    int comps;
    void init(int n) { p.assign(n, -1); r.assign(n, 0); comps = 0; }
    void add(int x) { p[x] = x; comps++; }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        comps--;
    }
};

int main() {
    int t; scanf("%d", &t);
    string out;
    out.reserve(1 << 20);
    static const int dr[4] = {-1, 0, 1, 0};
    static const int dc[4] = {0, 1, 0, -1};
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        int N = n * m;
        vector<int> g(N);
        for (int i = 0; i < N; i++) scanf("%d", &g[i]);
        int q; scanf("%d", &q);
        vector<int> imp(q);
        vector<char> hit(N, 0), present(N, 0);
        for (int i = 0; i < q; i++) {
            int r, c; scanf("%d %d", &r, &c);
            r--; c--;
            imp[i] = r * m + c;
            hit[imp[i]] = 1;
        }
        DSU dsu; dsu.init(N);
        long long E = 0, V = 0, C = 0;
        auto addCell = [&](int idx) {
            present[idx] = 1;
            V++; C++; // dsu add below
            dsu.add(idx);
            int r = idx / m, c = idx % m;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int nidx = nr * m + nc;
                if (!present[nidx]) continue;
                if (!(g[idx] & (1 << d))) continue;
                if (!(g[nidx] & (1 << ((d + 2) % 4)))) continue;
                E++;
                if (dsu.find(idx) == dsu.find(nidx)) { /* same comp */ }
                else { dsu.unite(idx, nidx); C--; }
            }
        };
        for (int i = 0; i < N; i++) if (!hit[i]) addCell(i);
        vector<long long> ans(q);
        if (q > 0) {
            ans[q - 1] = E - V + C;
            for (int j = q - 1; j >= 1; j--) {
                addCell(imp[j]);
                ans[j - 1] = E - V + C;
            }
        }
        for (int i = 0; i < q; i++) {
            if (i) out += ' ';
            out += to_string(ans[i]);
        }
        out += '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
