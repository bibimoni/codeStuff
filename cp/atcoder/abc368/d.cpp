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
#define int int64_t 

/**
 * Description: Finding LCA and Kth Ancestor using Binary Lifting
 * Caution:
 *    * adj must be one-indexed
 *    * root must be 1 (can be modified if required)
 * Source : https://oj.vnoi.info/submission/4618381
 * Verification : https://oj.vnoi.info/problem/hbtlca
 * 
 * usage LCA lca(n + 1, adj, root) // default root is 1
 */

struct LCA {
  vector<vector<int>> par;
  vector<vector<int>> adj;
  vector<int> dep;
  int LG; 
  void dfs(int u, int p = 0) {
    par[u][0] = p;
    for (int i = 1; i < LG; i++) 
      par[u][i] = par[par[u][i - 1]][i - 1];
    for (int v : adj[u]) {
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
 
  LCA (int _n, vector<vector<int>> &adj, int root = 1) : adj(adj) {
    int n = _n;
    LG = 64 - __builtin_clzll(n);
    par.assign(n, vector<int>(LG, 0));
    dep.assign(n, 0);
    dfs(root);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  LCA lca(n + 1, adj);
  vector<int> m(n + 1);
  vector<int> v(k);
  int god = -1;
  for (int i = 0; i < k; i++) {
    cin >> v[i];
    m[v[i]] = 1;
    if (god == -1) {
      god = v[i];
    } else {
      god = lca.lca(god, v[i]);
    }
  }
  int ans = 0;
  auto dfs = [&] (auto &&self, int u, int p) -> int {
    int cnt = m[u];
    for (auto v : adj[u]) {
      if (v == p) {
        continue;
      }
      cnt += self(self, v, u);
    }
    ans += cnt > 0;
    return cnt;
  };
  dfs(dfs, god, god);
  cout << ans << '\n';
}


