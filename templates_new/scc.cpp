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
