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
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  SCC scc(n + 1, adj);
  map<pair<int, int>, int> mp;
  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) {
      mp[{scc.root[u], scc.root[v]}] = 1;
    }
  }
  int st = -1;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (scc.root[i] != st) {
      ans.push_back(scc.root[i]);
      st = scc.root[i];
    } else if (scc.root[i] != st && st != -1) {
      ans.push_back(scc.root[i]);
      break;
    }
  }
  if (ans.size() <= 1) {
    cout << "YES\n";
    return 0;
  }
  if (mp[{ans[0], ans[1]}]) {
    swap(ans[0], ans[1]);
  }
  vector<int> ans2;
  for (int u = 1; u <= n; u++) {
    if (scc.root[u] == ans[0]) {
      ans2.push_back(u);
      break;
    }
  }

  for (int u = 1; u <= n; u++) {
    if (scc.root[u] == ans[1]) {
      ans2.push_back(u);
      break;
    }
  }

  if (ans2.size() <= 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n" << ans2[0] << " " << ans2[1] << "\n";
  }
}
