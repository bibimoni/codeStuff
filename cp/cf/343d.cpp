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

// lazy propagation with one-based indexing
//
// build:
//    lazySegtree<int> seg;
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(l, r, inc); //increase a[l -> r] += inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template <class T>
struct lazySegTree {
  vector<T> st, lazy;
  int n;
  lazySegTree() {}
  lazySegTree(int _n) : n(_n) {
    T default_value = 0;
    st.assign(4 * n, default_value);
    lazy.assign(4 * n, default_value);
  }  
  void build(const vector<T> &a) {
    build(a, 1, 1, n);
  }
  void build(const vector<T> &a, int id, int l, int r) {
    lazy[id] = 0;
    if(l == r) {
      if(l < a.size()) {
        st[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }
  void down(int id) {
    if(lazy[id] == 0)
      return;
    st[id * 2] = lazy[id];
    st[id * 2 | 1] = lazy[id];
    lazy[id * 2] = lazy[id];
    lazy[id * 2 | 1] = lazy[id];
    lazy[id] = 0;
  }
  void update(int u, int v, T val) {
    update(u, v, val, 1, 1, n);
  }
  void update(int u, int v, T val, int id, int l, int r) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id] = val;
      st[id] = val;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
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
    down(id);
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};

template<class T>
struct HLD {
  vector<vector<int>> adj;
  vector<int> parent, d, st, heavy, head, en;
  lazySegTree<int> seg;
  int timeDfs = 0;
  int dfs(int u) {
    int curr = 0, sz = 1;
    for (int v : adj[u]) {
      if (v == parent[u]) {
        continue;
      }
      parent[v] = u;
      d[v] = d[u] + 1;
      int c = dfs(v);
      sz += c;
      if (c > curr) {
        curr = c;
        heavy[u] = v;
      }
    }
    return sz;
  }

  void dfsChain(int u, int h) {
    st[u] = ++timeDfs;
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
    en[u] = timeDfs;
  }

  HLD() {}

  HLD(int n, vector<vector<int>> &adj) : adj(adj) {
    parent = vector<int>(n + 1, 1);
    d = vector<int>(n + 1);
    heavy = vector<int>(n + 1, -1);
    head = vector<int>(n + 1);
    st = vector<int>(n + 1);
    en = vector<int>(n + 1);
    seg = lazySegTree<int>(n + 1);
    timeDfs = 0;
    dfs(1);
    dfsChain(1, 1);
  }

  void update(int u, T val) {
    if (val == 0) {
      for(; head[u] != head[1]; u = parent[head[u]]) {
        seg.update(st[head[u]], st[u], val);
      }
      seg.update(1, st[u], val);
    } else {
      seg.update(st[u], en[u], val);
    }
  }

  T query(int u) {
    return seg.query(st[u], st[u]);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  HLD<int> hld(n, adj);
  int q;
  cin >> q;
  while (q--) {
    int c, v;
    cin >> c >> v;
    if (c == 1) {
      hld.update(v, 1);
    } else if (c == 2) {
      hld.update(v, 0);
    } else if (c == 3) {
      cout << hld.query(v) << '\n';
    }
  }
}

