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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int inf = 1e18;
  vector<vector<int>> dp(n + 2, vector<int>(n + 2, inf));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    dp[u][v] = min(dp[u][v], w);
    dp[v][u] = min(dp[v][u], w);
  }
  int k, t;
  cin >> k >> t;
  vector<int> d(n + 1);
  for (int i = 1; i <= k; i++) {
    cin >> d[i];
    dp[d[i]][n + 1] = min(dp[d[i]][n + 1], t);
    dp[n + 1][d[i]] = 0;
  }

  for (int i = 1; i <= n + 1; i++) {
    dp[i][i] = 0;
  }
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n + 1; j++) {
      for (int u = 1; u <= n + 1; u++) {
        if (dp[i][u] != inf && dp[u][j] != inf) {
          dp[i][j] = min(dp[i][u] + dp[u][j], dp[i][j]);
        }
      }
    }
  }

  auto relax = [&](int x, int y) -> void {
    for (int i = 1; i <= n + 1; i++) {
      for (int j = 1; j <= n + 1; j++) {
        if (dp[x][y] != inf) {
          dp[i][j] = min({dp[i][j], dp[i][x] + dp[x][y] + dp[y][j],
                          dp[i][y] + dp[y][x] + dp[x][j]});
        }
      }
    }
  };

  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, v, c;
      cin >> u >> v >> c;
      dp[u][v] = min(dp[u][v], c);
      dp[v][u] = min(dp[v][u], c);
      relax(u, v);
    } else if (op == 2) {
      int x;
      cin >> x;
      dp[x][n + 1] = min(dp[x][n + 1], t);
      dp[n + 1][x] = min(dp[n + 1][x], int(0));
      relax(x, n + 1);
      relax(n + 1, x);
    } else {
      int ret = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (dp[i][j] < inf)
            ret += dp[i][j];
        }
      }
      cout << ret << '\n';
    }
  }
}
