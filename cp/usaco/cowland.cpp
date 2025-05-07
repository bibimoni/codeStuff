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

template<class T>
struct segTree {
  vector<T> st;
  int n;

  segTree() {}

  segTree(int _n) : n(_n) {
    T default_value = 0;
    st.assign(4 * n, default_value);
  }
  void build(const vector<T> &a) {
    build(a, 1, 1, n);
  }
  void build(const vector<T>& a, int id, int l, int r) {
    if(l == r) {
      st[id] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] ^ st[id * 2 | 1];
  }
  void update(int pos, T inc) {
    update(pos, inc, 1, 1, n);
  }
  void update(int pos, T inc, int id, int l, int r) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id] = inc;
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] ^ st[id * 2 | 1];
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return 0;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return query(u, v, id * 2, l, mid) ^ query(u, v, id * 2 | 1, mid + 1, r);
  }
};

template <class T>
struct HLD {
  vector<vector<T>> adj;
  vector<int> parent, e, d, heavy, st, head;
  int timeDfs;
  segTree<int> seg;

  int dfs(int u) {
    int sz = 1;
    int maxChildSize = 0;
    for (int v : adj[u]) {
      if (parent[u] == v) {
        continue;
      }
      parent[v] = u;
      d[v] = d[u] + 1;
      int c = dfs(v);
      sz += c;
      if (c > maxChildSize) {
        maxChildSize = c;
        heavy[u] = v;
      }
    }
    return sz;
  }

  void dfsChain(int u, int h) {
    st[u] = ++timeDfs;
    seg.update(st[u], e[u]);
    head[u] = h;
    if (heavy[u] != -1) {
      dfsChain(heavy[u], h);
    }
    for (int v : adj[u]) {
      if (v == parent[u] || v == heavy[u]) {
        continue;
      }
      dfsChain(v, v);
    }
  }

  HLD(int n, vector<vector<T>> &adj_, vector<int> &e_) : adj(adj_), e(e_) {
    parent = vector<int>(n + 1, 1);
    d = vector<int>(n + 1);
    heavy = vector<int>(n + 1, -1);
    head = vector<int>(n + 1);
    st = vector<int>(n + 1);
    timeDfs = 0;
    seg = segTree<int>(n + 1);
    dfs(1);
    dfsChain(1, 1);
  }

  void update(int u, T v) {
    seg.update(st[u], v);
  }

  T query(int a, int b) {
    T ret = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
      if (d[head[a]] > d[head[b]]) {
        swap(a, b);
      }
      ret ^= seg.query(st[head[b]], st[b]);
    }   
    if (d[st[a]] > d[st[b]]) {
      swap(a, b);
    }
    ret ^= seg.query(st[a], st[b]);
    return ret; 
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("cowland.in", "r", stdin);
  freopen("cowland.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<int> e(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> e[i];
  }
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  HLD<int> hld(n, adj, e);
  while (q--) {
    int c;
    cin >> c;
    if (c == 1) {
      int i, v;
      cin >> i >> v;
      e[i] = v;
      hld.update(i, v);
    } else if (c == 2) {
      int u, v;
      cin >> u >> v;
      cout << hld.query(u, v) << '\n';
    }
  }
}

