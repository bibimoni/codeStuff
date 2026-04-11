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

template <class T> class Fenwick {
  vector<T> a;
  int n;

public:
  Fenwick() {}

  Fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n + 5, static_cast<T>(0));
  }

  T query(int r) {
    T q = 0; // check default value of query
    for (; r > 0; r -= (r & -r)) {
      q += a[r]; // check query modification
    }
    return q;
  }

  T query(int l, int r) {
    if (r < l) {
      return 0;
    }
    return query(r) - query(l - 1);
  }

  void update(int r, T del) {
    for (; r <= n; r += (r & -r)) {
      a[r] += del; // check update rule
    }
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<vector<pair<int, int>>> b(n + 1);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    b[r].push_back({l, i});
  }

  int sum = 0;
  Fenwick<int> ft(n + 1);
  vector<int> ans(q);
  for (int i = 1; i <= n; i++) {
    sum += i * a[i];
    ft.update(i, sum);

    int all = ft.query(1, i);
    for (auto [r, idx] : b[i]) {
      int part = ft.query(1, r - 1);
      ans[idx] = all - part;
      dbg(i, r, all, part, idx);
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}
