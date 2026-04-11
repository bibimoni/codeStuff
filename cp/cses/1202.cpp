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
  vector adj(n, vector<pair<int, int>>());
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u -= 1;
    v -= 1;
    adj[u].push_back({v, c});
  }

  const int64_t inf = 1e18;
  const int mod = 1e9 + 7;
  vector<int64_t> d(n, inf), cnt(n, 0), mx(n, 0), mn(n, inf);

  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
  pq.push({0, 0});
  cnt[0] = 1;
  d[0] = mx[0] = mn[0] = 0;
  while (pq.size()) {
    auto [w, u] = pq.top();
    pq.pop();
    if (d[u] != w) {
      continue;
    }
    for (auto [v, c] : adj[u]) {
      if (d[v] > d[u] + c) {
        cnt[v] = cnt[u];
        mx[v] = mx[u] + 1;
        mn[v] = mn[u] + 1;
        d[v] = d[u] + c;
        pq.push({d[v], v});
      } else if (d[v] == d[u] + c) {
        cnt[v] += cnt[u];
        cnt[v] %= mod;
        mx[v] = max(mx[v], mx[u] + 1);
        mn[v] = min(mn[v], mn[u] + 1);
        // pq.push({d[v], v});
      }
    }
  }

  cout << d[n - 1] << ' ' << cnt[n - 1] << ' ' << mn[n - 1] << ' ' << mx[n - 1]
       << '\n';
}
