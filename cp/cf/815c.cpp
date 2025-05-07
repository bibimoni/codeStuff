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

const int N = (int) 5e3 + 5, INF = (int) 2e9;
vector<int> adj[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, b; 
  cin >> n >> b;
  int c[n + 1], d[n + 1], x[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> c[i] >> d[i];
    if(i >= 2) {
      cin >> x[i];
      adj[i].push_back(x[i]);
      adj[x[i]].push_back(i);
    }
  }
  vector<int> sz(n + 1);
  vector<vector<int>> f(n + 1, vector<int>(n + 1, INF)), g(n + 1, vector<int>(n + 1, INF));
  for(int i = 1; i <= n; i++) {
    sz[i] = 1;
    f[i][1] = c[i] - d[i];
    g[i][0] = 0;
    g[i][1] = c[i];
  }
  function<void(int, int)> dfs = [&] (int u, int p)  {
    for(auto v : adj[u]) {
      if(v == p)
        continue;
      dfs(v, u);
      for(int a = sz[u]; a >= 0; a--) {
        for(int b = sz[v]; b >= 0; b--) {
          g[u][a + b] = min(g[u][a + b], g[u][a] + g[v][b]);
          f[u][a + b] = min(f[u][a + b], f[u][a] + min(f[v][b], g[v][b]));
        }
      }
      sz[u] += sz[v];
    }
  };
  dfs(1, -1);
  for(int i = n; i >= 0; i--) {
    if(min(f[1][i], g[1][i]) <= b) {
      cout << i;
      break;
    }
  }
}

