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
  int n, c0;

public:
  Fenwick() {}

  Fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n + 5, static_cast<T>(0));
    c0 = 0;
  }

  T query(int r) {
    T q = 0; // check default value of query
    for (; r > 0; r -= (r & -r)) {
      q += a[r]; // check query modification
    }
    return q + c0;
  }

  void update(int r, T del) {
    if (r == 0) {
      c0 += del;
      return;
    }
    for (; r <= n; r += (r & -r)) {
      a[r] += del; // check update rule
    }
  }

  T range(int l, int r) {
    if (l == 0)
      return query(r);
    return query(r) - query(l - 1);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
  }

  const int MX = 5e5;
  Fenwick<int> cnt(MX + 1);
  Fenwick<int> sum(MX + 1);

  for (int i = 1; i <= n; i++) {
    cnt.update(a[i], 1);
    sum.update(a[i], a[i]);
  }

  while (q--) {
    int opt;
    cin >> opt;
    dbg(opt);
    if (opt == 1) {
      int x, y;
      cin >> x >> y;
      cnt.update(a[x], -1);
      sum.update(a[x], -a[x]);
      a[x] = y;
      cnt.update(a[x], 1);
      sum.update(a[x], a[x]);
    } else if (opt == 2) {
      int l, r;
      cin >> l >> r;
      int ans;
      if (l <= r) {
        ans = sum.range(l, r) + cnt.range(0, l - 1) * l +
              cnt.range(r + 1, MX) * r;
      } else {
        ans = n * l;
      }
      cout << ans << '\n';
    }
  }
}
