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
const int INF = (int) 1e18, N = (int) 1e5 + 5;
vector<vector<int>> t;
vector<pair<int, int>> adj[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  t.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int x;
      cin >> x;
      t[i].push_back(x);
    }
  }
  set<pair<int, int>> s;
  vector<int> d(n + 1, INF);
  vector<int> vis(n + 1, 0);
  d[1] = 0;
  s.insert({0, 1});
  while(s.size()) {
    auto [_, u] = *s.begin();
    s.erase(s.begin());
    if(u == n) {
      break;
    }
    if(vis[u]) {
      continue;
    }
    vis[u] = 1;
    auto p = lower_bound(t[u].begin(), t[u].end(), d[u]);
    while(p != t[u].end() && d[u] == *p) {
      d[u]++;
      p = next(p);
    }
    for(auto [v, c] : adj[u]) {
      if(d[u] + c < d[v]) {
        d[v] = d[u] + c;
        s.insert({d[v], v});
      }
    }
  }
  cout << (d[n] == INF ? -1 : d[n]);
}

