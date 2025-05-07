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
#define all(_x) (_x).begin(), (_x).end()
#define sz(_x) (_x).size()

// segtree with one-based indexing
//
// build:
//    segtree<int, N> seg; // N is constant
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(pos, inc); //increase a[pos] to a[pos] + inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template<class T, int SZ>
struct SegTree {
  vector<T> st;
  SegTree() {
    T default_value = 0;
    st.assign(4 * SZ, default_value);
  }
  void build(const vector<T>& a, int id = 1, int l = 1, int r = SZ) {
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
  void update(int pos, T inc, int id = 1, int l = 1, int r = SZ) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id] += inc;
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
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
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};

/**
 * Description: Heavy-light decomposition for point updates
 * Complexity: Query - O((logN)^2); Update - O(logN)
 * Caution: SZ is the maxnimum number of vertices (in powers of 2) and the tree must be rooted
 * Source: https://cp-algorithms.com/graph/hld.html
 */

template <class T, int SZ>
struct HeavyLight {
  vector<vector<int>> g;
  SegTree<T, SZ> seg;
  vector<int> parent, depth, heavy, head, pos;
  int cur_pos;

  int dfs(int u) {
    int size = 1;
    int max_c_size = 0;
    for (int c : g[u]) {
      if (c == parent[u]) continue;
      parent[c] = u, depth[c] = depth[u] + 1;
      int c_size = dfs(c);
      size += c_size;
      if (c_size > max_c_size) {
        max_c_size = c_size;
        heavy[u] = c;
      }
    }
    return size;
  }

  void decomp(int v, int h) {
    head[v] = h;
    pos[v] = cur_pos++; // position of v in segtree
    if (~heavy[v]) {
      decomp(heavy[v], h);
    }
    for (int c : g[v]) {
      if (c != parent[v] && c != heavy[v]) {
        decomp(c, c);
      }
    }
  }

  HeavyLight() {}

  HeavyLight(vector<vector<T>> g_) : g(g_) {
    int n = sz(g);
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 1;
    dfs(0); // root of tree
    decomp(0, 0);
  }

  void update(int v, T val) {
    // updating value of vertex v
    seg.update(pos[v], val);
  }

  T query(int a, int b) {
    T res = 0; // default value for query
    for (; head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]]) swap(a, b);
      T cur = seg.query(pos[head[b]], pos[b]);
      // operation
      res += cur;
    }
    if (depth[a] > depth[b]) swap(a, b);
    T lst = seg.query(pos[a], pos[b]);
    // operation
    res += lst;
    return res;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    
  }
}

