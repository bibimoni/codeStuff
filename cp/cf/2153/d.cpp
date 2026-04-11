/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    const int inf = 1e18;
    auto get = [&](vector<int> b) -> int {
      auto cost = [&](int j, int i) -> int {
        vector<int> x;
        for (int k = j; k <= i; k++) {
          x.push_back(b[k]);
        }
        sort(x.begin(), x.end());
        return x[x.size() - 1] - x[0];
      };
      vector<int> dp(n, inf);
      for (int i = 0; i < n; i++) {
        int prev = (i == 0 ? 0 : dp[i - 1]);
        if (i + 2 < n) {
          dp[i + 2] = min(dp[i + 2], prev + cost(i, i + 2));
        }
        if (i + 1 < n) {
          dp[i + 1] = min(dp[i + 1], prev + cost(i, i + 1));
        }
      }
      dbg(dp);
      return dp[n - 1];
    };

    int ans = get(a);
    for (int cyc = 0; cyc < 4; cyc++) {
      rotate(a.rbegin(), a.rbegin() + 1, a.rend());
      ans = min(get(a), ans);
    }
    cout << ans << '\n';
  }
}
