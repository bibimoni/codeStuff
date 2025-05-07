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

const int N = (int) 1e5 + 5;
    int cntSub = 0, leaf = 1;
vector<int> adj[N];
void dfs(int u, int p = -1) {
  for(auto v : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
  }
  if(adj[u].size() == 1) {
    cntSub++;
  }
};
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    cntSub = 0;
    for(int i = 1; i <= n; i++) adj[i].clear();
    leaf = 1;
    for(int i = 0; i < n - 1; i++) {
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) if(adj[i].size() == 1) leaf = i;
    dfs(leaf);
    cout << (cntSub - 1) / 2 + 1 << '\n';
  }
}


