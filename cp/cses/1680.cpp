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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    deg[v] += 1;
    adj[u].push_back(v);
    g[v].push_back(u);
  }

  queue<int> que;
  for (int u = 0; u < n; u++) {
    if (deg[u] == 0) {
      que.push(u);
    }
  }

  vector<int> cands;
  while (que.size()) {
    int u = que.front();
    que.pop();
    cands.push_back(u);
    for (int v : adj[u]) {
      deg[v] -= 1;
      if (deg[v] == 0) {
        que.push(v);
      }
    }
  }
  if (int(cands.size()) != n) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  const int inf = 1e9;
  vector<int> dp(n, -inf), trace(n, -1);
  dp[0] = 1;
  for (int u : cands) {
    int cur = -1, mx = 0;
    for (int v : g[u]) {
      if (mx < dp[v] + 1) {
        mx = dp[v] + 1;
        cur = v;
      }
    }
    if (cur != -1) {
      trace[u] = cur;
      dp[u] = mx;
    }
  }

  if (dp[n - 1] == -inf) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  cout << dp[n - 1] << '\n';
  vector<int> ans{n - 1};
  for (int v = n - 1; v != 0; v = trace[v]) {
    ans.push_back(trace[v]);
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans) {
    cout << i + 1 << " ";
  }
}
