// time-limit: 3000
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
  int n;
  cin >> n;
  vector<pair<int, int>> seg(n);
  vector<int> s;
  for (int i = 0; i < n; i++) {
    cin >> seg[i].first >> seg[i].second;
    s.push_back(seg[i].second);
    s.push_back(seg[i].first - 1);
  }
  sort(s.begin(), s.end());
  auto idx = [&] (int v) -> int {
    return lower_bound(s.begin(), s.end(), v) - s.begin() + 1;
  };
  sort(seg.begin(), seg.end(), [&] (pair<int, int> i, pair<int, int> j) {
    return i.second < j.second;
  });
  int ans = 0;
  Fenwick<int> ft(int(s.size()) + 5);
  for (auto [l, r] : seg) {
    ans += ft.query(idx(r)) - ft.query(idx(l - 1));
    ft.update(idx(r), 1);
  }
  cout << ans << '\n';
}


