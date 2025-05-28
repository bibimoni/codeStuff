#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(int n, vector<int> &a, vector<int> &b, vector<vector<int>> &e,
                int budget) {
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);
    vector<int> deg(n + 1);
    for (auto p : e) {
      adj[p[0]].push_back(p[1]);
      rev[p[1]].push_back(p[0]);
      deg[p[1]] += 1;
    }

    queue<int> que;
    for (int u = 1; u <= n; u++) {
      if (deg[u] == 0) {
        que.push(u);
      }
    }
    vector<int> cands;
    while (que.size()) {
      int u = que.front();
      cands.push_back(u);
      que.pop();
      for (int v : adj[u]) {
        deg[v] -= 1;
        if (!deg[v]) {
          que.push(v);
        }
      }
    }

    cands.insert(cands.begin(), 0);
    cout << "ord\n";
    for (int u = 1; u <= n; u++) {
      cout << cands[u] << " \n"[u == n];
    }
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
      pos[cands[i]] = i;
    }

    cout << "pos\n";
    for (int u = 1; u <= n; u++) {
      cout << pos[u] << " \n"[u == n];
    }
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    const int INF = 1e9;
    vector<vector<array<int, 2>>> dp(
        n + 1, vector<array<int, 2>>(budget + 1, array<int, 2>{-INF, -INF}));
    dp[0] = vector<array<int, 2>>(budget + 1, array<int, 2>{0, -INF});
    for (int iter = 0; iter < n; iter++) {

    vector<vector<array<int, 2>>> ndp(
        n + 1, vector<array<int, 2>>(budget + 1, array<int, 2>{-INF, -INF}));
      for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= budget; w++) {
          int u = cands[i];
          // don't buy
          ndp[i][w][0] = max(dp[i - 1][w][0], dp[i - 1][w][1]);

          // buy
          if (w - a[u] >= 0) {
            ndp[i][w][1] =
              max(dp[i - 1][w - a[u]][1], dp[i - 1][w - a[u]][0]) + b[u] - a[u];
          }
          for (int v : rev[u]) {
            // cout << "child: " << v << " parent " << u << '\n';
            // ansc don't buy
            if (w - a[u] >= 0) {
              ndp[i][w][1] =
                max(dp[i][w][1], dp[pos[v]][w - a[u]][0] + b[u] - a[u]);
              // cout << "old v " << v << " pos[v] " << pos[v] << " w - a[u] "
              //      << w - a[u] << ' ' << dp[pos[v]][w - a[u]][0] << " dp before
              //      "
              //      << dp[i][w][1] << '\n';
              // cout << "i w dp " << i << ' ' << w << ' ' << dp[i][w][1] << '\n';
            }
            // ansc buy
            if (w - (a[u] / 2) >= 0) {
              ndp[i][w][1] =
                max(dp[i][w][1], dp[pos[v]][w - a[u] / 2][1] + b[u] - a[u] / 2);
            }
          }
        }
      }
      swap(ndp, dp);
    }
    int ans = 0;
    for (int w = 0; w <= budget; w++) {
      ans = max({ans, dp[n][w][0], dp[n][w][1]});
    }
    return ans;
  }
};
