#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
const int W = 2 * MAXN;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, Q;
    if (!(cin >> N >> M >> Q)) return 0;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // rows[i]: [A row | P row], A = I + adjacency
    vector< bitset<W> > a(N);
    for (int i = 0; i < N; i++) {
        a[i].set(i);          // I
        for (int nb : adj[i]) a[i].set(nb);
        a[i].set(MAXN + i);   // P = I
    }
    vector<int> pivcol; // pivot column per pivot row
    vector<int> isPivot(N, 0);
    int r = 0;
    for (int c = 0; c < N && r < N; c++) {
        int sel = -1;
        for (int i = r; i < N; i++) if (a[i].test(c)) { sel = i; break; }
        if (sel < 0) continue;
        swap(a[sel], a[r]);
        for (int i = 0; i < N; i++) if (i != r && a[i].test(c)) a[i] ^= a[r];
        pivcol.push_back(c);
        isPivot[c] = 1;
        r++;
    }
    // extract P rows (word-level structures for fast queries)
    vector< bitset<MAXN> > P(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) P[i].set(j, a[i].test(MAXN + j));
    for (int qi = 0; qi < Q; qi++) {
        string s;
        s.reserve(N);
        while ((int)s.size() < N) {
            string tok; cin >> tok;
            for (char ch : tok) if (ch == '0' || ch == '1') s.push_back(ch);
        }
        // c = 1 + s (deficit)
        bitset<MAXN> c;
        for (int i = 0; i < N; i++) c.set(i, (s[i] == '0')); // 1 + s_i
        // d = P * c (word-level)
        vector<int> d(N, 0);
        for (int i = 0; i < N; i++) d[i] = (int)((P[i] & c).count() & 1);
        bool ok = true;
        for (int i = r; i < N; i++) if (d[i]) { ok = false; break; }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        bitset<MAXN> x;
        for (int i = 0; i < r; i++) if (d[i]) x.set(pivcol[i]);
        // output
        int K = (int)x.count();
        cout << K;
        for (int i = 0; i < N; i++) if (x.test(i)) cout << ' ' << (i + 1);
        cout << '\n';
    }
    return 0;
}
