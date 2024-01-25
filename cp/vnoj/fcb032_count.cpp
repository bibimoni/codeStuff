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

const int N = (int) 2e5 + 1;
int n, idx[N], ans[N]; set<int> s[N]; vector<int> adj[N];

void dfs(int u, int p = -1) {
  for(int v : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
    int iU = idx[u], iV = idx[v];
    if(s[iU].size() >= s[iV].size()) {
      s[iU].insert(all(s[iV]));
    }
    else {
      s[iV].insert(all(s[iU]));
      idx[u] = idx[v];
    }
    ans[u] = s[idx[u]].size();
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
  for(int i = 1, x; i <= n; i++) cin >> x, idx[i] = i, s[i].insert(x), ans[i] = 1;
  dfs(1);
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

