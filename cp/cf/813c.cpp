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

#define int            long long
#define all(x)         x.begin(), x.end()
 
vector<int> adj[200005];
void dfs(vector<int>& d, int u, int p = -1) {
  for(auto v : adj[u]) {
    if(v == p) continue;
    d[v] = d[u] + 1;
    dfs(d, v, u);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int x, n;
  cin >> n >> x;
  for(int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> d1(n + 1, 0), dx(n + 1, 0);
  dfs(d1, 1); dfs(dx, x);
  dbg(d1, dx);
  int ans = d1[x] * 2;
  for(int i = 1; i <= n; i++) {
    if(dx[i] < d1[i]) {
      ans = max(ans, d1[i] * 2);
    }
    dbg(dx[i], d1[i]);
  }
  cout << ans;
}


