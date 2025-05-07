// time-limit: 3000
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

// segtree with one-based indexing
//
// build:
//    SegTree<int> seg(n); // vector<int> a(n + 1)
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(pos, inc); //increase a[pos] to a[pos] + inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template<class T>
struct SegTree {
  vector<T> st;
  int n;
  SegTree(int _n) : n(_n) {
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
    st[id] = st[id * 2] + st[id * 2 | 1];
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
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    int h_max = __builtin_ctzll(n + 1);
    vector<int> a(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
      cin >> a[i];
      adj[a[i]].push_back(i);
    }
    vector<int> p(n + 1);
    vector<int> idx(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      idx[p[i]] = i;
    }
    vector<int> good_sz(n + 1, 0);
    int vertex = 1;
    auto get = [&] (auto &&self, int h) -> void {
      int u = vertex;
      good_sz[u] = 1;
      if (h == 1) {
        return;
      }
      for (int i = 1; i <= 2; i++) {
        vertex += 1;
        int v = vertex;
        self(self, h - 1);
        good_sz[u] += good_sz[v];
      }
    };
    get(get, h_max);
    vector<int> sz(n + 1, 0);
    vector<int> parent(n + 1, 1);
    auto dfs = [&] (auto &&self, int u) -> void {
      sz[u] = 1;
      for (int v : adj[u]) {
        self(self, v);
        parent[v] = u;
        sz[u] += sz[v];
      }
    };
    dfs(dfs, 1);
    vector<int> p_size(n + 1);
    for (int i = 1; i <= n; i++) {
      p_size[i] = sz[p[i]];
    }
    vector<int> good_p(n + 1);
    SegTree<int> seg(n);
    seg.build(good_p);
    vector<int> good_parent(n + 1, 1);
    dbg(good_sz, good_parent);
    dbg(p_size, good_p, seg.query(1, n));
    while (q--) {
      int x, y;
      cin >> x >> y;
      idx[p[x]] = y;
      idx[p[y]] = x;
      swap(parent[p[x]], parent[p[y]]);
      swap(p[x], p[y]); 
      swap(adj[p[x]], adj[p[y]]);
      if (parent[p[x]] != p[x]) {
        int last = 0;
        for (int v : adj[parent[p[x]]]) {
          last += v;
        }
        last -= p[x];
        adj[parent[p[x]]] = {last, p[x]};
      }
      if (parent[p[y]] != p[y]) {
        int last = 0;
        for (int v : adj[parent[p[y]]]) {
          last += v;
        }
        last -= p[y];
        adj[parent[p[y]]] = {last, p[y]};
      }
      for (auto v : adj[p[x]]) {
        parent[v] = p[x];
      }
      for (auto v : adj[p[y]]) {
        parent[v] = p[y];
      }
      p_size[idx[p[x]]] = sz[p[x]];
      p_size[idx[p[y]]] = sz[p[y]];
      good_p[idx[p[x]]] = int(p_size[idx[p[x]]] == good_sz[idx[p[x]]]);
      good_p[idx[p[y]]] = int(p_size[idx[p[y]]] == good_sz[idx[p[y]]]);
      
      seg.update(idx[p[x]], good_p[idx[p[x]]]);
      seg.update(idx[p[y]], good_p[idx[p[y]]]);
      dbg(p_size, good_p, seg.query(1, n));
      cout << (seg.query(1, n) == n ? "YES\n" : "NO\n");
    }
  }
}


