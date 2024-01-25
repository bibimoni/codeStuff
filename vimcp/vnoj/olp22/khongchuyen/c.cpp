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
vector<int> adj[N], cnt(N, 0);
int m, n;
vector<bool> vis(N, false), vis1(N, false);

bool dfs(int u, int p = -1) {
  vis[u] = true;
  for(int v : adj[u]) {
    if(v == p) continue;
    if(vis[v]) {
      return true;
    }
    if(dfs(v, u)) return true;
  }
  return false;
} 

void dfs1(int u) {
  dbg(u);
  cnt[u]++;
  vis1[u] = true;
  for(int v : adj[u]) {
    if(vis1[v]) continue;
    dfs1(v);
    cnt[u] += cnt[v];
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m;
  for(int u, v, i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(!vis1[i]) {
      bool isCyc = dfs(i);
      dfs1(i);
      dbg(cnt[i], isCyc);
      ans += cnt[i] - 1 + isCyc;
    }
  }
  cout << ans;
}

