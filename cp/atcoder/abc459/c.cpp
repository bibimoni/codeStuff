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
    r += 1;
    if (r <= 0) {
      return 0;
    }
    T q = 0; // check default value of query
    for (; r > 0; r -= (r & -r)) {
      q += a[r]; // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    r += 1;
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

  const int Q = (int)1e6 + 5;
  vector<int> freq(Q);
  Fenwick<int> ft(Q);
  vector<int> val(n + 1);

  int base = 0;
  freq[base] = n;
  ft.update(base, n);

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      int old_f = val[x];
      val[x] += 1;
      freq[old_f] -= 1;
      freq[val[x]] += 1;
      ft.update(old_f, -1);
      ft.update(val[x], 1);
      if (freq[base] == 0) {
        base += 1;
      }
    } else {
      int y;
      cin >> y;
      cout << ft.query(Q) - ft.query(y + base - 1) << '\n';
    }
  }
}
