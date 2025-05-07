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

template <class T>
class Fenwick {
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
      a[r] += del; //check update rule
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  Fenwick<int> ft(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ft.update(i, a[i]);
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int k, u;
      cin >> k >> u;
      int old = ft.query(k) - ft.query(k - 1);
      ft.update(k, u - old);
    } else {
      int l, r;
      cin >> l >> r;
      cout << ft.query(r) - ft.query(l - 1) << "\n";
    }
  }
}

