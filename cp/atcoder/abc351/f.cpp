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
#define int            long long

template <class T>
class fenwick {
  vector<T> a;
  int n;

public:
  fenwick() {}

  fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n + 5, {0, 0});
  }

  T query(int r) {
    T q = {0, 0}; // check default value of query
    for (; r > 0; r -= (r & -r)) {
      q.first += a[r].first; // check query modification
      q.second += a[r].second;
    }
    return q;
  }

  void update(int r, int del) {
    for (; r <= n; r += (r & -r)) {
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
  vector<int> a(n);
  vector<int> s;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    s.push_back(a[i]);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  auto get = [&] (int num) -> int {
    return lower_bound(s.begin(), s.end(), num) - s.begin() + 1;
  };
  fenwick<pair<int, int>> ft(n + 1);
  ft.update(get(a[0]), a[0]);
  int ans = 0, cnt0 = 0;
  for(int i = 1; i < n; i++) {
    if(a[i] == 0) {
      cnt0++;
      continue;
    }
    auto [val, cnt] = ft.query(get(a[i]));
    ans += a[i] * (cnt + cnt0) - val;
    ft.update(get(a[i]), a[i]);
  }
  cout << ans;  
}


