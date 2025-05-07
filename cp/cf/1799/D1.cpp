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
    st[id] = min(st[id * 2], st[id * 2 | 1]);
  }
  void down(int id) {
    if(lazy[id] == 0)
      return;
    st[id * 2] += lazy[id];
    st[id * 2 | 1] += lazy[id];
    lazy[id * 2] += lazy[id];
    lazy[id * 2 | 1] += lazy[id];
    lazy[id] = 0;
  }
  void update(int u, int v, T val) {
    update(u, v, val, 1, 1, n);
  }
  void update(int u, int v, T val, int id, int l, int r) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id] += val;
      st[id] += val;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = min(st[id * 2], st[id * 2 | 1]);
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
    return min(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> cold(k + 1);
    for (int i = 1; i <= k; i++) {
      cin >> cold[i];
    }
    vector<int> hot(k + 1);
    for (int i = 1; i <= k; i++) {
      cin >> hot[i];
    }
    const int INF = int(1e18);
    // dp[i] = min cost if the current cpu do task a[i]
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      vector<int> ndp(n + 1, INF);
      for (int j = i - 1; j >= 0; j--) {
        ndp[i - 1] = min(ndp[i - 1], dp[j] + (a[j] == a[i] ? hot[a[i]] : cold[a[i]]));
        ndp[j] = min(ndp[j], dp[j] + (a[i] == a[i - 1] ? hot[a[i]] : cold[a[i]]));
      }
      swap(dp, ndp);
    }
    // dbg(dp);
    cout << *min_element(dp.begin(), dp.end()) << '\n';
  }
}

