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

const int N = (int) 1e5 + 5;
vector<pair<int, int>> adj[N];;
vector<int> ans(N), pref(N, 0);
/**
 * Description: Finding LCA and Kth Ancestor using Binary Lifting
 * Caution:
 *    * adj must be one-indexed
 *    * root must be 1 (can be modified if required)
 * Source : https://oj.vnoi.info/submission/4618381
 * Verification : https://oj.vnoi.info/problem/hbtlca
 * 
 * usage LCA lca(n + 1, root) // default root is 1
 */

struct LCA {
  vector<vector<int>> par;
  vector<int> dep;
  int LG; 
  void dfs(int u, int p = 0) {
    par[u][0] = p;
    for (int i = 1; i < LG; i++) 
      par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto [v, _] : adj[u]) {
      if (v == p) continue;
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
 
  int ancestor(int u, int k) {
    for (int i = 0; i < LG; i++) 
      if (k & (1 << i)) 
        u = par[u][i];
    return u;
  }
 
  int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = ancestor(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = LG - 1; i >= 0; i--)
      if (par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];
  }
 
  LCA (int _n, int root = 1) {
    int n = _n;
    LG = 64 - __builtin_clzll(n);
    par.assign(n, vector<int>(LG, 0));
    dep.assign(n, 0);
    dfs(root);
  }
};

void dfs(int u, int p = -1) {
  for(auto [v, _] : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
    pref[u] += pref[v];
  }
}

void dfs1(int u, int p = -1) {
  for(auto [v, i] : adj[u]) {
    if(v == p) continue;
    ans[i] = pref[v];
    dfs1(v, u);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1; i <= n - 1; i++) {
    int u, v; 
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  LCA lca(n + 1);
  int k; 
  cin >> k;
  while(k--) {
    int a, b;
    cin >> a >> b;
    pref[a]++;
    pref[b]++;
    pref[lca.lca(a, b)] -= 2;
  }
  dfs(1);
  dfs1(1);
  for(int i = 1; i <= n - 1; i++) {
    cout << ans[i] << ' ';
  }
}

