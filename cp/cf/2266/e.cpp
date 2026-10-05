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
#define int int64_t

// Computing smallest prime factor as sieve in O(nloglogn)
// Largest prime factor can be computed by removing (a[j] == 0) condition
vector<int> spf(int n) {
  n++;
  vector<int> a(n);
  a[1] = 1;
  for (int i = 2; i < n; i++) {
    if (a[i] == 0) {
      a[i] = i;
      for (int j = 2 * i; j < n; j += i) {
        if (a[j] == 0)
          a[j] = i;
      }
    }
  }
  return a;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    auto mnp = spf(n + 1);
    map<pair<int, int>, int> mp;

    auto dfs = [&] (auto &&self, int cur, int mul) -> int {
      if (cur <= k) {
        return 0;
      } 
      if (mp.count({cur, mul})) {
        return mp[make_pair(cur, mul)];
      }

      int ans = 1e9;
      int old_cur = cur;
      while (cur != 1) {
        int p = mnp[cur];
        ans = min(ans, mul + self(self, old_cur / p, mul * p));
        cur /= p;
      }

      mp[make_pair(old_cur, mul)] = ans;
      return ans;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans += dfs(dfs, x, 1);
    }
    cout << ans << '\n';
  }
}
