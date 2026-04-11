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
  int n;
  cin >> n;
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int64_t ans = 0;
  Fenwick<int> ftl(n + 1), ftr(n + 1);
  for (int i = 1; i <= n; i++) {
    ftr.update(b[i], 1);
  }

  for (int i = 1; i <= n; i++) {
    ftr.update(b[i], -1);
    ans += 1LL * (ftl.query(b[i] - 1) + 1) * (ftr.query(b[i] - 1) + 1);
    ftl.update(b[i], 1);
  }

  cout << ans << '\n';
}
