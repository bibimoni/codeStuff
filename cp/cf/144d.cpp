/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  int l;
  cin >> l;
  const int INF = 1e18;
  vector<int> d(n + 1, INF);
  d[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  while (pq.size()) {
    auto [wu, u] = pq.top();
    pq.pop();
    if (wu != d[u]) {
      continue;
    }
    for (auto [w, v] : adj[u]) {
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        pq.push({d[v], v});
      }
    }
  }
  int ans = 0;
  map<pair<int, int>, set<int>> f;
  for (int u = 1; u <= n; u++) {
    ans += d[u] == l;
    for (auto [w, v] : adj[u]) {
      if (d[u] >= l || l >= d[u] + w) {
        continue;
      }
      pair<int, int> e = {min(u, v), max(u, v)};
      int val = (u < v ? l - d[u] : l - d[v]);
      if(u < v && w - val + d[v] < val + d[u]) {
        continue;
      }
      if(u > v && w - val + d[u] <= val + d[v]) {
        continue;
      }
      val = (u < v ? l - d[u] : w - (l - d[u]));
      if (f[e].find(val) != f[e].end()) {
        continue;
      }
      f[e].insert(val);
      ans += 1;
    }
  }
  cout << ans;
}

