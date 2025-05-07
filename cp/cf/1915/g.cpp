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

#define int            long long

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m; cin >> n >> m;
    int s[n + 1];
    vector<pair<int, int>> adj[n + 1];
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 0, u, v, w; i < m; i++) {
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }  
    for(int i = 1; i <= n; i++) {
      cin >> s[i];
    }
    vector<vector<int>> d(n + 1, vector<int>(1011, INF));
    vector<vector<bool>> vis(n + 1, vector<bool>(1011, false));
    priority_queue<array<int, 3>> q;
    q.push({0ll, 1, s[1]}); // dist, node, bike
    d[1][s[1]] = 0ll;
    while(q.size()) {
      auto [w1, u, bike] = q.top(); 
      q.pop();
      if(vis[u][bike] || d[u][bike] == INF) continue;
      vis[u][bike] = true;
      for(auto [v, w] : adj[u]) {
        int currBike = min(bike, s[v]);
        if(d[v][currBike] > d[u][bike] + 1ll * bike * w) {
          d[v][currBike] = d[u][bike] + 1ll * bike * w;
          q.push({-d[v][bike], v, currBike});
        }
      } 
    }
    int ans = INF;
    for(int i = 1; i <= 1000; i++) {
      ans = min(ans, d[n][i]);
    }
    cout << ans<< '\n';
  }
}

