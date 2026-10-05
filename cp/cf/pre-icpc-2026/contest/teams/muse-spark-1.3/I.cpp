#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) { p.resize(n); r.assign(n, 0); iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int N = n * m;
        vector<int> g(N);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> g[i * m + j];
        int q;
        cin >> q;
        vector<int> qr(q), qc(q);
        for (int i = 0; i < q; i++) { cin >> qr[i] >> qc[i]; --qr[i]; --qc[i]; }
        vector<char> removed(N, 0);
        for (int i = 0; i < q; i++) removed[qr[i] * m + qc[i]] = 1;
        auto alive = [&](int id) -> bool { return g[id] != 0 && !removed[id]; };
        auto connected = [&](int r1, int c1, int r2, int c2) -> bool {
            // adjacent cells; check mutual openings
            int a = g[r1 * m + c1], b = g[r2 * m + c2];
            if (r2 == r1 + 1) return (a & 4) && (b & 1);
            if (r2 == r1 - 1) return (a & 1) && (b & 4);
            if (c2 == c1 + 1) return (a & 2) && (b & 8);
            if (c2 == c1 - 1) return (a & 8) && (b & 2);
            return false;
        };
        DSU dsu(N);
        long long V = 0, E = 0, C = 0;
        for (int id = 0; id < N; id++) if (alive(id)) { V++; C++; }
        const int dr[4] = {-1, 0, 1, 0};
        const int dc[4] = {0, 1, 0, -1};
        for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) {
            int id = r * m + c;
            if (!alive(id)) continue;
            // only count right and down to avoid double
            if (c + 1 < m && alive(id + 1) && connected(r, c, r, c + 1)) { E++; dsu.unite(id, id + 1); }
            if (r + 1 < n && alive(id + m) && connected(r, c, r + 1, c)) { E++; dsu.unite(id, id + m); }
        }
        // recount components among alive
        {
            unordered_set<int> roots;
            for (int id = 0; id < N; id++) if (alive(id)) roots.insert(dsu.find(id));
            C = (long long)roots.size();
        }
        vector<long long> rec;
        rec.reserve(q + 1);
        rec.push_back(E - V + C); // fwd[q]: all impacts applied
        for (int i = q - 1; i >= 0; i--) {
            int r = qr[i], c = qc[i], id = r * m + c;
            removed[id] = 0; // re-add
            V++; C++;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int nid = nr * m + nc;
                if (!alive(nid)) continue;
                if (connected(r, c, nr, nc)) {
                    E++;
                    if (dsu.unite(id, nid)) C--;
                }
            }
            rec.push_back(E - V + C);
        }
        for (int i = q - 1; i >= 0; i--) {
            if (i != q - 1) cout << ' ';
            cout << rec[i];
        }
        cout << "\n";
    }
    return 0;
}
