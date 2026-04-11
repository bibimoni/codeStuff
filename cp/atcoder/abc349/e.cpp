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
      q = max(q, a[r]); // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    for (; r <= n; r += (r & -r)) {
      a[r] = max(del, a[r]); // check update rule
    }
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> ki(n + 1);
  vector<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> ki[i].first >> ki[i].second;
    s.push_back(ki[i].second);
  }

  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());

  for (int i = 1; i <= n; i++) {
    ki[i].second =
        (int)(lower_bound(s.begin(), s.end(), ki[i].second) - s.begin() + 1);
  }

  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    mp[ki[i].first].push_back(ki[i].second);
  }

  Fenwick<int> ft(n);
  int ans = 0;
  for (auto [i, p] : mp) {

    vector<int> tmp;
    for (auto j : p) {
      int val = ft.query(j - 1) + 1;
      ans = max(ans, val);
      tmp.push_back(val);
    }

    int idx = 0;
    for (auto j : p) {
      ft.update(j, tmp[idx]);
      idx += 1;
    }
  }

  cout << ans << '\n';
}
