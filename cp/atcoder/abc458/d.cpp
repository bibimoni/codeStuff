/**
 * Author: distiled
 */
#include <algorithm>
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
  int x;
  cin >> x;
  int q;
  cin >> q;
  vector<pair<int, int>> que;
  vector<int> s{x};
  for (int i = 0; i < q; i++) {
    int y, z;
    cin >> y >> z;
    que.push_back({y, z});
    s.push_back(y);
    s.push_back(z);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  auto ff = [&](int v) -> int {
    return lower_bound(s.begin(), s.end(), v) - s.begin() + 1;
  };

  Fenwick<int> ft((int)s.size() + 5);
  ft.update(ff(x), 1);
  int cnt = 1;
  for (auto [a, b] : que) {
    ft.update(ff(a), 1);
    ft.update(ff(b), 1);
    cnt += 1;
    int lo = 0, hi = (int)s.size() - 1, ans = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      int v = ft.query(ff(s[mid]));
      if (v >= cnt) {
        ans = s[mid];
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    cout << ans << '\n';
  }
}
