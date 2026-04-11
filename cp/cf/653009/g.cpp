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
// #define int int64_t

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

  void update(int r, T del) {
    for (; r <= n; r += (r & -r)) {
      a[r] += del; // check update rule
    }
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("median.inp", "r", stdin);
  // freopen("median.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end(), b.end()));

  int med = b[(n + 1) / 2];
  auto calc = [&](int c) -> int64_t {
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
      v[i] = int(lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1);
    }
    if (c == 0) {
      return 0;
    }
    Fenwick<int> ft(n + 1);
    int64_t ret = 0;
    for (int i = 1; i <= n; i++) {
      ft.update(i, a[i] <= c ? 1 : -1);
      if (ft.query(i) >= 0) {
        ret += 1;
      }
      ret += max(0, ft.query(i));
    }
    return ret;
  };
  cout << calc(med) - calc(med - 1) << '\n';
}
