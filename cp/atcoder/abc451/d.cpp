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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> base;
  int s = 1;
  for (int i = 0; i < 30; i++) {
    base.push_back(s);
    s *= 2;
  }
  vector<int> p10(10, 1);
  for (int i = 1; i <= 9; i++) {
    p10[i] = p10[i - 1] * 10;
  }
  auto len = [&](int x) -> int {
    if (x == 0) {
      return 1;
    }
    int ret = 0;
    while (x) {
      x /= 10;
      ret += 1;
    }
    return ret;
  };

  vector<int64_t> ll;
  auto dfs = [&](auto &&self, int64_t x) -> void {
    if (x != 0) {
      ll.push_back(x);
    }
    for (auto v : base) {
      int64_t nv = 1LL * x * p10[len(v)] + v;
      if (nv > int64_t(1e9)) {
        continue;
      }
      self(self, nv);
    }
  };
  dfs(dfs, 0);
  sort(ll.begin(), ll.end());
  ll.erase(unique(ll.begin(), ll.end()), ll.end());
  cout << ll[n - 1];
}
