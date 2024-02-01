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

const int N = (int) 1e5 + 5, LG = 20;

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
struct gcdSegTree {
  vector<T> st;
  gcdSegTree() {
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
    st[id] = __gcd(st[id * 2], st[id * 2 | 1]);
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
    st[id] = __gcd(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) {
      return 0;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return __gcd(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

template<class T>
struct RMQ {
  T st[LG + 1][N];
  int n;
  void build (const vector<T> &a) {
    n = a.size();
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
      for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  T query(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; 
  cin >> n;
  vector<int> a(n + 1);
  map<int, vector<int>> f;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    f[a[i]].push_back(i);
  }
  gcdSegTree<int, N> seg;
  seg.build(a);
  RMQ<int> rmq;
  rmq.build(a);
  int tt;
  cin >> tt;
  while(tt--) {
    int l, r; 
    cin >> l >> r;
    int minValue = rmq.query(l, r);
    int gcdValue = seg.query(l, r);
    if(minValue != gcdValue) {
      cout << r - l + 1 << '\n';
      continue;
    }
    int lt = 1, rt = n;
    int pl = lower_bound(f[minValue].begin(), f[minValue].end(), l) - f[minValue].begin();
    int pr = upper_bound(f[minValue].begin(), f[minValue].end(), r) - f[minValue].begin() - 1;
    cout << r - l + 1 - (pr - pl + 1) << '\n';
  }
}

