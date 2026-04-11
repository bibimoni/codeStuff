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
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  string s;
  cin >> s;
  s = " " + s;

  const int inf = 1e9;
  vector<int> d1(n + 1, inf), d2(n + 1, inf);
  queue<int> que;
  for (int u = 1; u <= n; u++) {
    if (s[u] == 'S') {
      que.push(u);
      d1[u] = 0;
      d2[u] = 0;
    }
  }

  while (que.size()) {
    int u = que.front();
    que.pop();
  }
}
