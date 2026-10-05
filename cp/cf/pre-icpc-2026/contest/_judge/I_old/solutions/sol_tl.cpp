// Correct but slow: brute-force forward simulation, recounting V, E, C from
// scratch after every impact. O(q * n * m) per test case -> TL on big tests.
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
        for (int v = 0; v < N; v++) active[v] = g[v] != 0;
        for (int i = 0; i < q; i++) {
            active[str[i]] = false;
            long long V = 0, E = 0, C = 0;
            for (int v = 0; v < N; v++) {
                if (!active[v]) continue;
                V++;
                int r = v / m, c = v % m;
                for (int d = 0; d < 4; d++) {
                    if (!(g[v] >> d & 1)) continue;
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    int u = nr * m + nc;
                    if (active[u] && (g[u] >> (d ^ 2) & 1)) E++;
                }
            }
            E /= 2;
            vector<char> vis(N, false);
            for (int s = 0; s < N; s++) {
                if (!active[s] || vis[s]) continue;
                C++;
                queue<int> qq;
                qq.push(s);
                vis[s] = true;
                while (!qq.empty()) {
                    int v = qq.front(); qq.pop();
                    int r = v / m, c = v % m;
                    for (int d = 0; d < 4; d++) {
                        if (!(g[v] >> d & 1)) continue;
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                        int u = nr * m + nc;
                        if (active[u] && (g[u] >> (d ^ 2) & 1) && !vis[u]) {
                            vis[u] = true;
                            qq.push(u);
                        }
                    }
                }
            }
            if (i) cout << ' ';
            cout << E - V + C;
        }
        cout << '\n';
    }
    return 0;
}
