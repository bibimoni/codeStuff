/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <cstdio>
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
      if (v == p)
        continue;
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
    if (dep[u] < dep[v])
      swap(u, v);
    u = ancestor(u, dep[u] - dep[v]);
    if (u == v)
      return u;
    for (int i = LG - 1; i >= 0; i--)
      if (par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];
  }

  LCA(int _n, vector<vector<int>> &adj, int root = 1) : adj(adj) {
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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m + 1);
  vector<pair<int, int>> p(2 * n + 2, {-1, -1});
  vector<int> cl(2 * n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    edges[i] = {u, v};
    p[v] = {u, i};
    cl[u] = i;
    cl[v] = -i;
  }
  p[2 * n + 1] = {0, 0}; // Segments aren't contained by any other segments
  vector<pair<int, int>> que;

  vector<vector<int>> adj(2 * n + 1);
  set<pair<int, int>, greater<pair<int, int>>> ll;
  for (int i = 1; i <= 2 * n + 1; i++) {
    auto [u, id] = p[i];
    if (u == -1) {
      continue;
    }
    vector<pair<int, int>> ll_2;
    for (auto it : ll) {
      auto [u1, id1] = it;
      if (u1 < u) {
        break;
      }
      adj[id].push_back(id1);
      adj[id1].push_back(id);
      ll_2.push_back({u1, id1});
    }
    for (auto pp : ll_2) {
      ll.erase(pp);
    }
    ll.insert({u, id});
  }

  stack<int> st;
  st.push(0);
  vector<int> ms(2 * n + 1);
  for (int i = 1; i <= n * 2; i++) {
    if (cl[i] > 0) {
      st.push(cl[i]);
    }
    ms[i] = st.top();
    if (cl[i] < 0) {
      st.pop();
    }
  }

  LCA lca(2 * n + 1, adj, 0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    int dad = lca.lca(ms[u], ms[v]);
    cout << lca.dep[ms[u]] + lca.dep[ms[v]] - 2 * lca.dep[dad] << '\n';
  }
}
