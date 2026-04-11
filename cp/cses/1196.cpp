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
  int n, m, k;
  cin >> n >> m >> k;
  vector adj(n, vector<pair<int, int>>());
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u -= 1;
    v -= 1;
    adj[u].push_back({v, c});
  }

  vector<priority_queue<int64_t>> d(n);

  const int64_t inf = int64_t(1e18);
  d[0].push(0);

  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
  pq.push({0, 0});
  while (pq.size()) {
    auto [w, u] = pq.top();
    pq.pop();
    if (w > d[u].top()) {
      continue;
    }

    for (auto [v, c] : adj[u]) {
      int64_t w1 = w + c;
      if (d[v].size() < k) {
        d[v].push(w1);
        pq.push({w1, v});
      } else if (w1 < d[v].top()) {
        d[v].pop();
        d[v].push(w1);
        pq.push({w1, v});
      }
    }
  }

  vector<int64_t> ans;
  while (d[n - 1].size()) {
    ans.push_back(d[n - 1].top());
    d[n - 1].pop();
  }
  reverse(ans.begin(), ans.end());

  for (int64_t i : ans) {
    cout << i << ' ';
  }
}
