
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

const int N = (int) 4e5 + 5, C = 61;
int c[N];
vector<int> adj[N];
// lazy propagation with one-based indexing
//
// build:
//    lazySegtree<int, N> seg; // N is constant
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(l, r, inc); //increase a[l -> r] += inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template <class T, int SZ>
struct lazySegTree {
  vector<T> st;
  vector<T> lazy;
  lazySegTree() {
    T default_value = 0;
    st.resize(4 * SZ, 0);
    lazy.assign(4 * SZ, default_value);
  }  
  void build(const vector<T> &a, int id = 1, int l = 1, int r = SZ) {
    lazy[id] = 0;
    if(l == r) {
      if(l < a.size()) {
        st[id] = (1ll << a[l]);
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = (st[id * 2] | st[id * 2 | 1]);
  }
  void down(int id) {
    if(lazy[id] != 0) {
      st[id * 2] = (1ll << lazy[id]);
      st[id * 2 | 1] = (1ll << lazy[id]);
      lazy[id * 2] = lazy[id];
      lazy[id * 2 | 1] = lazy[id];
      lazy[id] = 0;
    }
  }
  void update(int u, int v, T val, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id] = val;
      st[id] = (1ll << val);
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = (st[id * 2] | st[id * 2 | 1]);
  }
  T query(int u, int v, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) {
      return 0;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    down(id);
    return query(u, v, id * 2, l, mid) | query(u, v, id * 2 | 1, mid + 1, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1, 0);
  lazySegTree<int, N> seg;
  for(int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> st(n + 1), en(n + 1);
  int id = 0;
  function<void(int, int)> dfs = [&] (int u, int p) {
    st[u] = ++id;
    for(int v : adj[u]) {
      if(v == p)
        continue;
      dfs(v, u);
    }
    en[u] = id;
  };
  dfs(1, -1);
  for(int i = 1; i <= n; i++) {
    a[st[i]] = c[i];
  }
  seg.build(a);
  while(m--) {
    int t; 
    cin >> t;
    if(t == 1) {
      int v, c;
      cin >> v >> c;
      seg.update(st[v], en[v], c);
    }
    else if(t == 2) {
      int v;
      cin >> v;
      cout << __builtin_popcountll(seg.query(st[v], en[v])) << '\n';
    }
  }
}

