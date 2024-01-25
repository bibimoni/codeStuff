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

const int N = 1e2 + 5;
vector<pair<int, int>> adj[N];
bool vis[N], can = false;
void dfs(int u, int dest, int color, int p = -1) {
  if(can) return;
  if(vis[u]) return;
  vis[u] = true;
  if(dest == u) can = true;
  for(auto [v, c] : adj[u]) {
    if(p == v || c != color) continue;
    dfs(v, dest, color, u);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; 
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, c; cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int u, v;
    cin >> u >> v;
    int ans = 0;
    for(int i = 1; i <= m; i++) {
      memset(vis, false, sizeof vis);
      can = false;
      dfs(u, v, i);
      ans += (int) can;
    }
    cout << ans << '\n';
  }
}

