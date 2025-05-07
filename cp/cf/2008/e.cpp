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
      st[id] += inc;
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    
    array<vector<int>, 26> even, odd;
    for (int k = 0; k < 26; k++) {
      even[k] = vector<int>(n + 1, 0);
      for (int i = 2; i <= n; i += 2) {
        even[k][i] = (s[i] - 'a' == k);
      }
      odd[k] = vector<int>(n + 1, 0);
      for(int i = 1; i <= n; i += 2) {
        odd[k][i] = (s[i] - 'a' == k);
      }
      for (int i = 1; i <= n; i++) {
        even[k][i] += even[k][i - 1];
        odd[k][i] += odd[k][i - 1];
      }
    }
    
    int ans = n;

    auto get_max = [&] (int i, array<vector<int>, 26> &st, array<vector<int>, 26> &st_2) -> int {
      int ret = 0;
      for (int k = 0; k < 26; k++) {
        ret = max(ret, st[k][i - 1] + st_2[k][n] - st_2[k][i]);
      }
      return ret;
    };

    auto get_max_2 = [&] (array<vector<int>, 26> &st) -> int {
      int ret = 0;
      for (int k = 0; k < 26; k++) {
        ret = max(ret, st[k][n]);
      }
      return ret;
    };

    if (n % 2 != 0) {
      for (int i = 1; i <= n; i++) {
        int to = get_max(i, even, odd);
        int te = get_max(i, odd, even);
        ans = min(ans, n - to - te);
      }
    } else {
      ans = min(ans, n - get_max_2(odd) - get_max_2(even));
    }
    cout << ans << '\n';
  }
}


