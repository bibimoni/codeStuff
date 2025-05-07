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
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> b(n + 1);
    int root = -1;
    for(int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    int u = 1;
    while(b[u] != u) {
      u = b[u];
    }    
    root = u;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    vector<int> ans(n + 1, 0);
    vector<int> vis(n + 1, 0);
    vector<int> dist(n + 1, 0);
    vis[root] = 1;
    bool ok = true; 
    int curr = 0;
    for(int i = 1; i <= n; i++) {
      int parent = b[p[i]];
      if(!vis[parent]) {
        ok = false;
        break;
      }
      if(p[i] == root)
        continue;
      ans[p[i]] = max(1ll, curr - dist[parent] + 1);
      dist[p[i]] = dist[parent] + ans[p[i]];
      curr = dist[p[i]];
      vis[p[i]] = 1;
    }
    for(int i = 1; i < n; i++) {
      if(dist[p[i]] >= dist[p[i + 1]]) {
        ok = false;
        break;
      }
    }
    if(!ok) {
      cout << "-1\n";
      continue;
    }
    for(int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
}

