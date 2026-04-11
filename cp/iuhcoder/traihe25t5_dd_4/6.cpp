#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto sqrtt = [&](int x, int base) -> int {
    int lo = 1, hi = x, ret = 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      int cur = 1;
      for (int j = 0; j < base; j++) {
        if (cur > int(1e18) / mid) {
          return 1;
        }

        cur *= mid;
      }
      if (cur <= x) {
        ret = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return ret;
  };

  auto pow = [&](int x, int pwr) -> int {
    int ret = 1;
    for (int j = 0; j < pwr; j++) {
      ret *= x;
    }
    return ret;
  };

  int n;
  cin >> n;
  map<int, int> ans;
  const int inf = 1e9;
  const int BOUND = 1e8;
  auto dfs = [&](auto &&self, int cur, int &tryy) -> int {
    tryy += 1;
    if (cur == 0) {
      return 0;
    }
    if (ans.count(cur)) {
      return ans[cur];
    }
    if (tryy > BOUND) {
      return inf;
    }
    int base = 2;
    int best = inf;
    int val;
    // cout << "cur " << cur << '\n';
    if (cur > n) {
      return inf;
    }
    while ((val = sqrtt(cur, base)) > 1) {
      // cout << "cur val " << cur << ' ' << val << '\n';
      for (int x = val; x >= 2; x--) {
        // cout << x << ' ' << base << ' ' << cur << '\n';
        best = min(best, self(self, cur - pow(x, base), tryy) + base);
      }
      base += 1;
    }
    best = min(cur * 2, best);
    ans[cur] = best;
    return ans[cur];
  };

  int tryy = 0;
  dfs(dfs, n, tryy);
  cout << ans[n];
}
