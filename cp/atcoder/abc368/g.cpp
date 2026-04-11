/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <system_error>
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

  T query(int l, int r) {
    if (l == 1) {
      return query(r);
    } else if (l > r) {
      return 0;
    }
    return query(r) - query(l - 1);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  Fenwick<int64_t> ft(n);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ft.update(i, a[i]);
  }

  vector<int> b(n + 1);
  set<int> st;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] > 1) {
      st.insert(i);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int i, x;
      cin >> i >> x;
      ft.update(i, -a[i]);
      ft.update(i, x);
      a[i] = x;
    } else if (opt == 2) {
      int i, x;
      cin >> i >> x;
      if (b[i] > 1) {
        st.erase(i);
      }
      if (x > 1) {
        st.insert(i);
      }
      b[i] = x;
    } else {
      int l, r;
      cin >> l >> r;
      auto nxt = [&](int id) -> int {
        auto it = st.lower_bound(id);
        if (it == st.end()) {
          return n + 1;
        }
        return *it;
      };
      int64_t ans = a[l];
      l += 1;
      while (l <= r) {
        int id = min(r, nxt(l));
        ans += ft.query(l, id - 1);
        ans = max(ans + a[id], ans * b[id]);
        l = id + 1;
      }
      cout << ans << '\n';
    }
  }
}
