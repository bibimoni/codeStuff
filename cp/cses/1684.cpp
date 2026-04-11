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
// #define int int64_t

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
    joint = vector<int>(n);
    timeDfs = scc = 0;
    for (int u = 1; u < n; u++) {
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(2 * m + 2);
  auto neg = [&](int u) -> int { return u > m ? u - m : u + m; };
  for (int i = 0; i < n; i++) {
    char c1, c2;
    int u, v;
    cin >> c1 >> u >> c2 >> v;
    if (c1 == '-') {
      u = neg(u);
    }
    if (c2 == '-') {
      v = neg(v);
    }

    adj[neg(u)].push_back(v);
    adj[neg(v)].push_back(u);
  }

  SCC scc(2 * m + 2, adj);
  bool ok = true;
  for (int i = 1; i <= m; i++) {
    if (scc.root[i] == scc.root[neg(i)]) {
      ok = false;
      break;
    }
  }

  if (!ok) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  for (int i = 1; i <= m; i++) {
    cout << (scc.root[i] < scc.root[neg(i)] ? '+' : '-') << " \n"[i == m];
  }
}
