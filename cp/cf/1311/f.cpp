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
    a.assign(n + 5, {0, 0});
  }

  T query(int r) {
    T q = {0, 0}; // check default value of query
    for (; r <= n; r += (r & -r)) {
      q.first += a[r].first; // check query modification
      q.second += a[r].second;
    }
    return q;
  }

  void update(int r, int del) {
    for (; r > 0; r -= (r & -r)) {
      a[r].first += del; //check update rule
      a[r].second += 1;       
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  vector<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
    s.push_back(a[i].second);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  auto idx = [&] (int val) -> int {
    return lower_bound(s.begin(), s.end(), val) - s.begin() + 1;
  };
  sort(a.begin() + 1, a.end());
  int ans = 0;
  Fenwick<pair<int, int>> ft(int(s.size()) + 5);
  for (int i = n; i >= 1; i--) {
    auto [val, cnt] = ft.query(idx(a[i].second));
    ans += val - cnt * a[i].first;
    ft.update(idx(a[i].second), a[i].first);
  }
  cout << ans << '\n';
}

