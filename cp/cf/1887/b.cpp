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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < t; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int u, v;
      cin >> u >> v;
      u -= 1;
      v -= 1;
      adj[u].emplace_back(v, i);
      adj[v].emplace_back(u, i);
    }
  }

  int k;
  cin >> k;
  vector<int> a(k);
  vector<vector<int>> travels(t);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    a[i] -= 1;
    travels[a[i]].emplace_back(i);
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.emplace(0, 0);
  const int INF = int(1e9);
  vector<int> d(n, INF);

  while (pq.size()) {
    auto [dist, u] = pq.top();
    pq.pop();
    if (d[u] != INF) {
      continue;
    }
    d[u] = dist;
    for (auto [v, t] : adj[u]) {
      auto it = lower_bound(travels[t].begin(), travels[t].end(), dist);
      if (it == travels[t].end()) {
        continue;
      }
      pq.emplace(*it + 1, v);
    }
  }
  cout << (d[n - 1] == INF ? -1 : d[n - 1]);
}

