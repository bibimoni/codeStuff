/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int long long

const int INF = (int) 1e18, N = 3e5 + 5;

// min query segtree with one-based indexing
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
struct minSegTree {
  vector<T> st;
  minSegTree() {
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
    st[id] = min(st[id * 2], st[id * 2 | 1]);
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
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) {
      return INF;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return min(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

// max query segtree with one-based indexing
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
struct maxSegTree {
  vector<T> st;
  maxSegTree() {
    T default_value = {0, 0};
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
    st[id] = max(st[id * 2], st[id * 2 | 1]);
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
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) {
      return {-INF, 0};
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return max(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<pair<int, int>> b(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = {a[i], i};
  }
  minSegTree<int, N> stm;
  maxSegTree<pair<int, int>, N> stM;
  stm.build(a);
  stM.build(b);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans++;
    int pos = i, l = i, r = n;
    while(l <= r) {
      int mid = (l + r) >> 1;
      int t = stm.query(i, mid);
      if(t == a[i]) {
        l = mid + 1;
        pos = mid;
      }
      else {
        r = mid - 1;
      }
    }
    l = i, r = pos;
    int bound = pos;
    int tmp = stM.query(i, pos).second;
    l = tmp, r = pos;
    while(l <= r) {
      int mid = (l + r) >> 1;
      int t = stM.query(mid, pos).first;
      if(a[tmp] == t) {
        l = mid + 1;
      }
      else {
        r = mid - 1;
        bound = mid - 1;
      }
    }
    if(bound == n) {
      break;
    }
    i = bound;
  }
  cout << ans;
}

