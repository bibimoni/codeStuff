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
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    deg[v] += 1;
    adj[u].push_back(v);
  }

  queue<int> que;
  for (int u = 0; u < n; u++) {
    if (deg[u] == 0) {
      que.push(u);
    }
  }

  vector<int> ans;
  while (que.size()) {
    int u = que.front();
    que.pop();
    ans.push_back(u);
    for (int v : adj[u]) {
      deg[v] -= 1;
      if (deg[v] == 0) {
        que.push(v);
      }
    }
  }

  if ((int)ans.size() != n) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (int i = 0; i < n; i++) {
      cout << ans[i] + 1 << " \n"[i == n - 1];
    }
  }
}
