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

struct LCA {
  vector<vector<int>> adj;
  vector<vector<int>> par;
  vector<int> dep;
  int LG;
  int n;
  LCA(int _n, vector<vector<int>>& _adj, int root = 1) : n(_n), adj(_adj) {
    LG = 64 - __builtin_clzll(n);
    par.assign(n, vector<int>(LG, 0));
    dep.assign(n, 0);
    dfs(root);
  }

  void dfs(int u, int p = -1) {
    par[u][0] = p;
    for (int j = 1; j < LG; j++) {
      par[u][j] = par[par[u][j - 1]][j - 1];
    }
    for (int v : adj[u]) {
      if (p == v) {
        continue;
      }
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }

  int ancestor(int u, int d) {
    for (int j = 0; j < LG; j++) {
      if ((d >> j) & 1) {
        u = par[u][j];
      }
    }
    return u;
  }

  int lca(int u, int v) {
    if (dep[u] < dep[v]) {
      swap(u, v);
    }
    u = ancestor(u, dep[u] - dep[v]);
    if (u == v) {
      return u;
    }
    for (int j = LG - 1; j > 0; j--) {
      if (par[u][j] != par[v][j]) {
        u = par[u][j];
        v = par[v][j];
      }
    }
    return par[u][0];
  }
};

struct SegTree {
  vector<int> st;
  int n;
  SegTree(int _n) : n(_n) {
    st.assign(4 * n + 5, 0);
  }

  void build(const vector<int> &a) {
    build(a, 1, 1, n);
  }

  void build(const vector<int> &a, int id, int l, int r) {
    if (l == r) {
      if ((int)a.size() > l) {
        st[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }

  void update(int pos, int val) {
    update(pos, val, 1, 1, n);
  }

  void update(int pos, int val, int id, int l, int r) {
    if (r < pos || pos < l) {
      return;
    }
    if (l == r) {
      st[id] += val;
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, val, id * 2, l, mid);
    update(pos, val, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }

  int query(int u, int v) {
    return query(u, v, 1, 1, n);
  }

  int query(int u, int v, int id, int l, int r) {
    if (v < l || r < u) {
      return 0;
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return query(u, v, id * 2, l, mid) + 
      query(u, v, id * 2 | 1, mid + 1, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> st(n + 1), en(n + 1);
  vector<int> ord(n + 1);
  int time_dfs = 0;
  auto dfs = [&] (auto &&self, int u, int p) -> void {
    time_dfs += 1;
    st[u] = time_dfs;
    ord[st[u]] = u;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      self(self, v, u);
    }
    en[u] = time_dfs;
  };

  dfs(dfs, 1, 1);
  SegTree seg(n);
  vector<set<int>> s(k + 1);
  for (int i = 1; i <= n; i++) {
    s[c[i]].insert(st[i]);
  }

  while (m--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int a, b;
      cin >> a >> b;
      
      c[a] = b;
    } else if (opt == 2) {
      int a;
      cin >> a;
    }
  }
}

