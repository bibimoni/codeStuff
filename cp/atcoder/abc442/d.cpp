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
  int n, q;
  cin >> n >> q;
  Fenwick<int> ft(n + 1);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ft.update(i, a[i]);
  }

  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x;
      cin >> x;
      ft.update(x, -a[x]);
      ft.update(x + 1, -a[x + 1]);
      swap(a[x], a[x + 1]);
      ft.update(x, a[x]);
      ft.update(x + 1, a[x + 1]);
    } else {
      int l, r;
      cin >> l >> r;
      cout << ft.query(r) - ft.query(l - 1) << '\n';
    }
  }
}
