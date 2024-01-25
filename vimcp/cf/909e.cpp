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
  int n, m;
  cin >> n >> m;
  int e[n];
  for(int i = 0; i < n; i++) {
      cin >> e[i];
  }
  vector<int> adj[n];
  vector<int> depends(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
    depends[u]++;
  }
  queue<int> co, pr;
  for(int i = 0; i < n; i++) {
    if(depends[i] == 0) {
      if(e[i])
        co.push(i);
      else
        pr.push(i);
    }
  }
  int ans = 0;
  while(co.size() || pr.size()) {
    while(pr.size()) {
      int u = pr.front();
      pr.pop();
      for(int v : adj[u]) {
        depends[v]--;
        if(depends[v] == 0) {
          if(e[v])
            co.push(v);
          else 
            pr.push(v);
        }
      }
    }
    ans += co.size() > 0;
    while(co.size()) {
      int u = co.front();
      co.pop();
      for(int v : adj[u]) {
        depends[v]--;
        if(depends[v] == 0) {
          if(e[v])
            co.push(v);
          else 
            pr.push(v);
        }
      }
    }
  }   
  cout << ans;
}

