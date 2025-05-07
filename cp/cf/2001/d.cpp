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

const int LG = 20, INF = (int) 2e9;

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
  bool op;
  SegTree(int _n, bool o) : n(_n), op(o) {
    T default_value = {0, 0};
    st.assign(4 * n, default_value);
  }
  void update(int pos, int inc) {
    update(pos, inc, 1, 1, n);
  }
  void update(int pos, int inc, int id, int l, int r) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id] = {inc, l};
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
    // st[id] = max(st[id * 2], st[id * 2 | 1]);
    pair<int, int> q1 = st[id * 2];
    pair<int, int> q2 = st[id * 2 | 1];
    if (op) {
      if (q1 > q2) {
        st[id] = q1;
      } else {
        st[id] = q2;;
      }
    } else {
      if (q1 < q2) {
        st[id] = q2;
      } else {
        st[id] = q1;
      }
    }
  }
  pair<int, int> query(int u, int v) {
    if (v - u + 1 < 1) {
      return {-INF, -1};
    }
    return query(u, v, 1, 1, n);
  }
  pair<int, int> query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return {-INF, -1};
    }
    if(u <= l && r <= v) {
      return {st[id].first, r};
    }
    int mid = (l + r) >> 1;
    pair<int, int> q1 = query(u, v, id * 2, l, mid);
    pair<int, int> q2 = query(u, v, id * 2 | 1, mid + 1, r);
    if (op) {
      if (q1 > q2) {
        return q1;
      } else {
        return q2;
      }
    } else {
      if (q1 < q2) {
        return q2;
      } else {
        return q1;
      }
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> t[i];
    }
    vector<int> a{0};
    for (int i = 1; i <= n; i++) {
      if (t[i] == a.back()) {
        continue;
      } 
      a.push_back(t[i]);
    }
    n = a.size() - 1;
    SegTree<pair<int, int>> sth(n, true), stl(n, false);
    vector<int> ans;
    vector<int> dp(n + 1, 0);
    vector<int> len(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      auto [mx, _] = max(sth.query(1, t[i] - 1), sth.query(t[i] + 1, n));
      len[i] = mx + 1;
      if (mx % 2 == 0) {
        // use max
        auto q1 = sth.query(1, t[i] - 1);
        auto q2 = sth.query(t[i] = 1, n);
        int num = (q1.first > q2.first ? q1.second : (q1.first < q2.first ? q2.second : q2.second));
        stl.update(num, mx + 1);
        sth.update(num, mx + 1);
        dp[num] = t[i];
      } else {
        // use min
        auto q1 = stl.query(1, t[i] - 1);
        auto q2 = stl.query(t[i] = 1, n);
        int num = (q1.first > q2.first ? q1.second : (q1.first < q2.first ? q2.second : q1.second));
        stl.update(num, mx + 1);
        sth.update(num, mx + 1);
        dp[num] = t[i];
      }
    }
    dbg(len);
  }
}


