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
  vector<int> findMedian(int n, vector<vector<int>> &edges,
                         vector<vector<int>> &queries) {
    vector<vector<int>> g(n);
    vector<vector<pair<int, int>>> adj(n);
    for (auto p : edges) {
      adj[p[0]].push_back({p[1], p[2]});
      adj[p[1]].push_back({p[0], p[2]});

      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }

    vector<long long> dist(n);
    vector<int> h(n);
    auto dfs = [&](auto &&self, int u, int p) -> void {
      for (auto [v, w] : adj[u]) {
        if (v == p) {
          continue;
        }
        dist[v] = dist[u] + w;
        h[v] = h[u] + 1;
        self(self, v, u);
      }
    };
    dfs(dfs, 0, 0);

    LCA lca(n, g, 0);
    auto findNode = [&](int distt, int ff, int ss, int ansc, int bound) -> int {
      if (ansc == ff || ansc == ss) {
        if (h[ff] > h[ss]) {
          return lca.ancestor(ff, distt);
        } else {
          return lca.ancestor(ss, bound - distt);
        }
      } else {
        int cur = min(distt, h[ff] - h[ansc]);
        int ret = lca.ancestor(ff, cur);
        distt -= cur;
        if (distt == 0) {
          return ret;
        } else {
          return lca.ancestor(ss, h[ss] - h[ansc] - distt);
        }
      }
    };

    auto calc = [&](int u, int v) -> long long {
      return dist[u] + dist[v] - 2LL * dist[lca.lca(u, v)];
    };
    vector<int> ans;
    for (auto p : queries) {
      int u = p[0], v = p[1];
      int ansc = lca.lca(u, v);
      int bound = h[u] + h[v] - 2 * h[ansc];
      int lo = 0, hi = h[u] + h[v] - 2 * h[ansc];
      int ret = u;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int node = findNode(mid, u, v, ansc, bound);
        long long dist1 = calc(u, node);
        long long dist2 = calc(node, v);
        if (dist1 >= dist2) {
          ret = node;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      ans.push_back(ret);
    }
    return ans;
  }
};
