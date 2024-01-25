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

const int N = (int) 2e5 + 5;
int n, a[N]; set<int> s[N]; vector<int> adj[N]; 
int ans[N], id[N];
void dfs(int u, int p = -1) {
  for(int v : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
    if(s[id[v]].size() > s[id[u]].size()) {
      s[id[v]].insert(all(s[id[u]]));
      id[u] = id[v];
    }
    else {
      s[id[u]].insert(all(s[id[v]]));
    }
    ans[u] = s[id[u]].size();
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n;
  for(int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; i++) cin >> a[i], id[i] = i, s[i].insert(a[i]);
  dfs(1);
  for(int i = 1; i <= n; i++) cout << ans[i] << ' '; 
}



