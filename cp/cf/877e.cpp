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

const int N = 2e5 + 5;
vector<int> adj[N];
int st[N], en[N], m = 0;

void dfs(int u, int p = -1) {
  st[u] = ++m;
  for(int v : adj[u]) {
    if(v == p)
      continue;
    dfs(v, u);
  }
  en[u] = m;
}

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
  vector<T> st, lazy;
  lazySegTree() {
    T default_value = 0;
    st.assign(4 * SZ, default_value);
    lazy.assign(4 * SZ, default_value);
  }  
  void build(const vector<T> &a, int id = 1, int l = 1, int r = SZ) {
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
  void down(int id, int l, int r) {
    if(lazy[id] == 0)
      return;
    lazy[id * 2] ^= lazy[id];
    lazy[id * 2 | 1] ^= lazy[id];
    int mid = (l + r) >> 1;
    st[id * 2] = (mid - l + 1) - st[id * 2];
    st[id * 2 | 1] = (r - mid) - st[id * 2 | 1];
    lazy[id] = 0;
  }
  void update(int u, int v, T val = 1, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id] ^= val;
      st[id] = (r - l + 1) - st[id]; //invert
      return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }
  T query(int u, int v, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) {
      return 0;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> t(n + 1);
  for(int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[i].push_back(p);
    adj[p].push_back(i);
  }
  dfs(1);
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> t[i];
    a[st[i]] = t[i];
  }
  lazySegTree<int, N> seg;
  seg.build(a);
  int q;
  cin >> q;
  while(q--) {
    string s;
    int v;
    cin >> s >> v;
    if(s == "get") {
      cout << seg.query(st[v], en[v]) << '\n';
    }
    else if(s == "pow") {
      seg.update(st[v], en[v]);
    }
  }
}

