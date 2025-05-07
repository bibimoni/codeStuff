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

const int N = (int) 2e5 + 5;
vector<int> adj[N];
bool isLeaf[N];

void dfs(int u, int p = -1) {
  bool leaf = true;
  for(int v : adj[u]) {
    if(v == p)
      continue;
    dfs(v, u);
    if(isLeaf[v]) //if one of child is leaf, this can't be leaf
      leaf = false;
  }
  isLeaf[u] = leaf;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
      isLeaf[i] = false;
    }
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1);
    int ans = 0;
    for(int i = 2; i <= n; i++) {
      if(isLeaf[i]) 
        ans++;
      else 
        ans--;
    }    
    if(isLeaf[1])
      ans++;
    cout << ans << '\n';
  }
}

