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

struct SegTree {
  vector<int> st, lazy;
  int n;
  SegTree(int _n) : n(_n) {
    st.assign(4 * n + 5, int(0));
    lazy.assign(4 * n + 5, int(0));
  }

  void build(const vector<pair<int, int>> &a) {
    build(a, 1, 1, n);
  }

  void build(const vector<pair<int, int>> &a, int id, int l, int r) {
    if (l == r) {
      if ((int)a.size() > l) {
        st[id] = a[l].second;
      }
      return;
    }
    dbg(id);
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }

  void down(int id) {
    if (lazy[id] == 0) {
      return;
    }
    st[id * 2] += lazy[id];
    st[id * 2 | 1] += lazy[id];
    lazy[id * 2] += lazy[id];
    lazy[id * 2 | 1] += lazy[id];
    lazy[id] = 0;
  }

  void update(int u, int v, int val) {
    update(u, v ,val, 1, 1, n);
  }

  void update(int u, int v, int val, int id, int l, int r) {
    if (v < l || r < u) {
      return;
    }
    if (u <= l && r <= v) {
      st[id] += val;
      lazy[id] += val;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }

  int query(int u, int v) {
    return query(u, v, 1, 1, n);
  }

  int query(int u, int v, int id, int l, int r) {
    if (v < l || r < u) {
      return 0;
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    down(id);
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
    }

    sort(a.begin() + 1, a.end());
    SegTree st(n);
    st.build(a);
    auto get_l = [&] (int day) -> int {
      int lo = 1, hi = n, ret = -1;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (a[mid].first >= day) {
          ret = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      return ret;
    };
    auto get_r = [&] (int day) -> int {
      int lo = 1, hi = n, ret = -1;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (a[mid].first <= day) {
          lo = mid + 1;
          ret = mid;
        } else {
          hi = mid - 1;
        }
      }
      return ret;
    };
    int ans = 0;
    for (int day = a[1].first; day < a.back().first + k; day++) {
      int lo = get_l(day - k + 1);
      int hi = get_r(day);
      if (lo == -1 || hi == -1) {
        continue;
      }
      
    }
  }
}

