// I - Impact on Polaris Deep: independent loops = E - V + C, maintained in reverse
#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p;
    DSU(int n) : p(n, -1) {}
    int find(int a) { int r = a; while (p[r] != -1) r = p[r]; while (a != r) { int nx = p[a]; p[a] = r; a = nx; } return r; }
    bool uni(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        p[a] = b; return true;
    }
};
int main() {
    int t;
    cin >> t;
    string out;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int N = n * m;
        vector<int> g(N);
        for (int i = 0; i < N; i++) cin >> g[i];
        int q;
        cin >> q;
        vector<int> hit(N, -1), ord(q);
        for (int i = 0; i < q; i++) { int r, c; cin >> r >> c; --r; --c; int id = r * m + c; hit[id] = i; ord[i] = id; }
        DSU dsu(N);
        vector<char> act(N, 0);
        long long V = 0, E = 0, C = 0;
        auto edge = [&](int u, int v) {           // connection exists?
            int r = u / m, c = u % m;
            if (v == u + 1) return (g[u] & 2) && (g[v] & 8);
            if (v == u - 1) return (g[u] & 8) && (g[v] & 2);
            if (v == u + m) return (g[u] & 4) && (g[v] & 1);
            if (v == u - m) return (g[u] & 1) && (g[v] & 4);
            return false;
        };
        auto addCell = [&](int u) {
            act[u] = 1; V++; C++;
            if (u % m + 1 < m && act[u + 1] && edge(u, u + 1)) { E++; if (dsu.uni(u, u + 1)) C--; }
            if (u % m > 0 && act[u - 1] && edge(u, u - 1)) { E++; if (dsu.uni(u, u - 1)) C--; }
            if (u + m < N && act[u + m] && edge(u, u + m)) { E++; if (dsu.uni(u, u + m)) C--; }
            if (u - m >= 0 && act[u - m] && edge(u, u - m)) { E++; if (dsu.uni(u, u - m)) C--; }
        };
        for (int i = 0; i < N; i++)
            if (g[i] != 0 && hit[i] < 0) addCell(i);
        vector<long long> ans(q);
        auto rec = [&](int i) { ans[i] = E - V + C; };
        if (q > 0) rec(q - 1);
        for (int i = q - 1; i >= 0; i--) {
            addCell(ord[i]);
            if (i > 0) rec(i - 1);
        }
        for (int i = 0; i < q; i++) { if (i) out += ' '; out += to_string(ans[i]); }
        out += '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);
}
