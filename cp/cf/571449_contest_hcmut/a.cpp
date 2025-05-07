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


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("paint.inp", "r", stdin);
  // freopen("paint.out", "w", stdout);
  int n, p, q;
  cin >> n >> p >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  auto ok = [&] (int w) -> bool {
    const int inf = int(1e18);
    vector<vector<int>> dp(n + 1, vector<int>(min(n + 1, p + 1), inf));
    int small = 1, large = 1;
    for (int j = 0; j <= min(n, p); j++) {
      dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
      while (small <= i && a[i] - a[small] + 1 > w) {
        small += 1;
      }
      while (large <= i && a[i] - a[large] + 1 > 2 * w) {
        large += 1;
      }
      for (int j = 0; j <= min(n, p); j++) {
        if (j == 0) {
          dp[i][j] = min(dp[i][j], dp[large - 1][j] + 1);
        } else {
          dp[i][j] = min({dp[i][j], dp[small - 1][j - 1], dp[large - 1][j] + 1});
        }
      }
    }
    bool check = false;
    for (int j = 0; j <= min(n, p); j++) {
      check |= dp[n][j] <= q;
    }
    return check;
  };

  int l = 0, r = int(1e9), ans = 1e9;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (ok(m)) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  cout << ans << '\n';
}