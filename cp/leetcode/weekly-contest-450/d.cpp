#include <bits/stdc++.h>
using namespace std;

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
class Solution {
public:
  vector<int> minimumWeight(vector<vector<int>> &edges,
                            vector<vector<int>> &queries) {
    int n = edges.size() + 1;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> adj1(n);
    for (auto p : edges) {
      int u = p[0], v = p[1], w = p[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      adj1[u].push_back(v);
      adj1[v].push_back(u);
    }
    LCA lca(n, adj1, 0);
    vector<int> ws(n, 0);
    vector<int> tin(n, 0), tout(n, 0);
    vector<int> h(n);
    int time_dfs = 1;
    auto dfs = [&] (auto &&self, int u, int p) -> void {
      tin[u] = time_dfs;
      time_dfs += 1;
      for (auto [v, w] : adj[u]) {
        if (p == v) {
          continue;
        }
        ws[v] = ws[u] + w;
        h[v] = h[u] + 1;
        self(self, v, u);
      }
      tout[u] = time_dfs;
    };

    auto inPath = [&] (int u, int v) -> bool {
      bool ok = tin[u] <= tin[v] && tout[v] <= tout[u];
      swap(u, v);
      ok |= tin[u] <= tin[v] && tout[v] <= tout[u];
      return ok;
    };

    dfs(dfs, 0, 0);
    vector<int> ans;
    for (auto p : queries) {
      vector<int> ns(p.begin(), p.end());
      sort(ns.begin(), ns.end(), [&] (int u, int v) {
          return h[u] < h[v];
          });
      int u1 = ns[0], u2 = ns[1], u3 = ns[2];
      int dad = lca.lca(u1, lca.lca(u2, u3));
      int ret = ws[u1] + ws[u2] + ws[u3] - 3 * ws[dad];
      if (inPath(u1, u2) && inPath(u2, u3)) {
        ret = min(ret, ws[u3] - ws[u1]);
      } 
      // u1 u2 
      int dad1 = lca.lca(u1, u2);
      ret = min(ret, ws[u1] + ws[u2] - ws[dad1] + ws[u3] - 2 * ws[dad]);

      // u1 u3 
      int dad2 = lca.lca(u1, u3);
      ret = min(ret, ws[u1] + ws[u3] - ws[dad2] + ws[u2] - 2 * ws[dad]);

      // u3 u2 
      int dad3 = lca.lca(u3, u2);
      ret = min(ret, ws[u3] + ws[u2] - ws[dad3] + ws[u1] - 2 * ws[dad]);
      
      ans.push_back(ret);
    }
    return ans;
  }
};
