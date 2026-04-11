/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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

vector<int> dst;
int find_idx(int x) {
  return lower_bound(dst.begin(), dst.end(), x) - dst.begin();
}

template <class T> struct SegTree {
  vector<T> st;
  int n;
  SegTree(int _n) : n(_n) {
    T default_value = {0, 0};
    st.assign(4 * n + 5, default_value);
  }
  void update(int u, int v, int val) { update(u, v, val, 1, 1, n); }

  void update(int u, int v, int val, int id, int l, int r) {
    if (v < l || u > r) {
      return;
    }
    if (u <= l && r <= v) {
      st[id].first += val;
    } else {
      int mid = (l + r) / 2;
      update(u, v, val, id * 2, l, mid);
      update(u, v, val, id * 2 + 1, mid + 1, r);
    }

    if (st[id].first > 0) {
      st[id].second = dst[r] - dst[l - 1];
    } else {
      if (l != r) {
        st[id].second = st[id * 2].second + st[id * 2 + 1].second;
      } else {
        st[id].second = 0;
      }
    }

    // cerr << dst[l] << " " << dst[r] << " " << st[id].second << endl;
    // cerr << l << " " << r << endl;
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, w;
  cin >> n >> w;
  vector<pair<int, int>> queries;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    int l = x - y;
    int r = x + y;
    int tl = max(l, int(0));
    int tr = min(r, w);
    queries.push_back({l, r});
    dst.push_back(tl);
    dst.push_back(tr);
  }

  sort(dst.begin(), dst.end());
  dst.erase(unique(dst.begin(), dst.end()), dst.end());

  // for (int i = 0; i < n; i++) {
  // queries[i] = {find_idx(queries[i].first), find_idx(queries[i].second)};
  // }

  SegTree<pair<int, int>> segtree(dst.size() + 1);
  set<pair<int, int>> vers;

  long double can2 = sqrt(2);

  for (int i = 0; i < n; i++) {
    auto [l, r] = queries[i];
    int il = find_idx(max(l, int(0)));
    int ir = find_idx(min(r, w));

    if (vers.find({l, r}) != vers.end()) {
      segtree.update(il - 1, ir, -1);
      vers.erase({l, r});
    } else {
      segtree.update(il - 1, ir, +1);
      vers.insert({l, r});
    }

    cout << fixed << setprecision(9) << can2 * segtree.st[1].second << endl;
  }
}
