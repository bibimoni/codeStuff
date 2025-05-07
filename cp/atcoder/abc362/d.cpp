// time-limit: 3000
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  const int INF = int(1e18);
  vector<int> d(n + 1, INF);
  d[1] = a[1];
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({d[1], 1});
  while (pq.size()) {
    auto [x, u] = pq.top();
    pq.pop();
    if (d[u] != x) {
      continue;
    }
    for (auto [w, v] : adj[u]) {
      if (d[u] + w + a[v] < d[v]) {
        d[v] = d[u] + w + a[v];
        pq.push({d[v], v});
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    cout << d[i] << " \n"[i == n];
  }
}


