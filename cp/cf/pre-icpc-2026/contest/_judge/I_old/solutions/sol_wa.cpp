// Tempting but wrong: forward simulation where destroying a junction with d
// active connections is assumed to remove exactly d-1 independent loops.
// False whenever the junction's neighbours belong to several components
// after its removal while loops exist elsewhere (cut-junction inside a
// loopy network) -> WA. Clamped at 0 to look plausible.
#include <bits/stdc++.h>
using namespace std;

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, 1, 0, -1};

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
        for (auto& s : str) {
            int r, c;
            cin >> r >> c;
            s = (r - 1) * m + (c - 1);
        }
        vector<char> active(N);
        long long V = 0, E = 0, C = 0;
        for (int v = 0; v < N; v++) {
            active[v] = g[v] != 0;
            if (g[v]) V++;
        }
        for (int v = 0; v < N; v++) {
            if (!g[v]) continue;
            int r = v / m, c = v % m;
            for (int d = 0; d < 4; d++) { // count each edge once, at the higher index
                if (!(g[v] >> d & 1)) continue;
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int u = nr * m + nc;
                if (u < v && (g[u] >> (d ^ 2) & 1)) E++;
            }
        }
        vector<char> vis(N, false);
        for (int s = 0; s < N; s++) {
            if (!active[s] || vis[s]) continue;
            C++;
            stack<int> st;
            st.push(s);
            vis[s] = true;
            while (!st.empty()) {
                int v = st.top(); st.pop();
                int r = v / m, c = v % m;
                for (int d = 0; d < 4; d++) {
                    if (!(g[v] >> d & 1)) continue;
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    int u = nr * m + nc;
                    if (active[u] && (g[u] >> (d ^ 2) & 1) && !vis[u]) {
                        vis[u] = true;
                        st.push(u);
                    }
                }
            }
        }
        long long loops = E - V + C;
        for (int i = 0; i < q; i++) {
            int v = str[i];
            int r = v / m, c = v % m;
            int d = 0;
            for (int k = 0; k < 4; k++) {
                if (!(g[v] >> k & 1)) continue;
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int u = nr * m + nc;
                if (active[u] && (g[u] >> (k ^ 2) & 1)) d++;
            }
            active[v] = false;
            loops = max(0LL, loops - max(0, d - 1));
            if (i) cout << ' ';
            cout << loops;
        }
        cout << '\n';
    }
    return 0;
}
