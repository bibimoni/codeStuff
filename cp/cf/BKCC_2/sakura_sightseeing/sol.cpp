/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

/*
 * Find Strongest connected component, joint, bridge of a DAG
 * Usage:
 * vector<vector<int>> adj(n + 1);
 * SCC scc(n + 1, adj, 1); (OR) SCC scc(n + 1, adj)
 *    Note: this work on 1 based index graph with n node (so you need to set n
 * here is n + 1, size of adj is also n + 1)
 *
 */
struct SCC {
  vector<int> low, num, del, root;
  int n;
  vector<vector<int>> adj;
  int timeDfs, scc;
  stack<int> st;
  vector<pair<int, int>> bridge;
  vector<int> joint;
  SCC(int _n, vector<vector<int>> &_adj, int src) : n(_n), adj(_adj) {
    low = vector<int>(n);
    num = vector<int>(n);
    del = vector<int>(n);
    root = vector<int>(n);
    joint = vector<int>(n);
    timeDfs = scc = 0;
    dfs(src, src);
  }
  SCC(int _n, vector<vector<int>> &_adj) : n(_n), adj(_adj) {
    low = vector<int>(n);
    num = vector<int>(n);
    del = vector<int>(n);
    root = vector<int>(n);
    timeDfs = scc = 0;
    for (int u = 1; u <= n; u++) {
      if (!num[u]) {
        dfs(u, u);
      }
    }
  }

  void dfs(int u, int pre) {
    timeDfs += 1;
    num[u] = low[u] = timeDfs;
    st.push(u);
    int child = 0;
    for (int v : adj[u]) {
      if (del[v]) {
        continue;
      }
      if (!num[v]) {
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] == num[u]) {
          bridge.push_back({u, v});
        }
        if (u == pre) {
          if (child > 1) {
            joint[u] = 1;
          }
        } else if (low[v] >= num[u]) {
          joint[u] = 1;
        }
      } else {
        low[u] = min(low[u], num[v]);
      }
    }
    if (low[u] == num[u]) {
      scc += 1;
      int v;
      do {
        v = st.top();
        st.pop();
        root[v] = scc;
        del[v] = 1;
      } while (v != u);
    }
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> h[i];

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    vector<vector<int>> adj(n + 1);
    for (int u = 1; u <= n; u++) {
      adj[u].push_back((u + a[u] - 1) % n + 1);
      adj[u].push_back((u - a[u] - 1 + n) % n + 1);
    }

    SCC scc(n + 1, adj, 1);

    vector<int> val(n + 1);
    for (int u = 1; u <= n; u++) {
      val[scc.root[u]] += h[u];
    }

    vector<vector<int>> g(n + 1);
    auto addEdge = [&](int u, int v) -> void {
      if (scc.root[u] == scc.root[v] || scc.root[u] == 0 || scc.root[v] == 0) {
        return;
      }
      g[scc.root[u]].push_back(scc.root[v]);
    };
    for (int u = 1; u <= n; u++) {
      addEdge(u, (u + a[u] - 1) % n + 1);
      addEdge(u, (u - a[u] - 1 + n) % n + 1);
    }

    vector<int> dp(n + 1, -1);
    auto dfs = [&](auto &&self, int u) -> int {
      if (g[u].empty()) {
        return val[u];
      }
      if (dp[u] != -1) {
        return dp[u];
      }
      int cur = 0;
      for (auto v : g[u]) {
        cur += self(self, v);
      }
      return dp[u] = cur;
    };

    cout << dfs(dfs, scc.root[1]) << '\n';
  }
}
