/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <queue>
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
  vector adj(n * 2, vector<pair<int, int>>());
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u -= 1;
    v -= 1;
    adj[u].push_back({v, c});
    adj[u + n].push_back({v + n, c});
    adj[u].push_back({v + n, c / 2});
  }

  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
  const int64_t inf = 1e18;
  vector<int64_t> d(n * 2, inf);
  pq.push({0, 0});
  d[0] = 0;
  while (pq.size()) {
    auto [w, u] = pq.top();
    pq.pop();
    if (d[u] != w) {
      continue;
    }
    for (auto [v, c] : adj[u]) {
      if (d[v] > d[u] + c) {
        d[v] = d[u] + c;
        pq.push({d[v], v});
      }
    }
  }

  cout << min(d[2 * n - 1], d[n - 1]);
}
