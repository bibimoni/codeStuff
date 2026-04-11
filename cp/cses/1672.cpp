/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  const int64_t inf = int64_t(1e18);
  vector dist(n, vector(n, inf));
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u -= 1;
    v -= 1;
    dist[u][v] = min(dist[u][v], (int64_t)c);
    dist[v][u] = min(dist[v][u], (int64_t)c);
  }
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
  }

  for (int k = 0; k < n; k++) {
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        if (dist[u][k] < inf && dist[k][v] < inf) {
          dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }
      }
    }
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    cout << (dist[u][v] < inf ? dist[u][v] : -1) << '\n';
  }
}
