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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  const int64_t INF = 4e18;
  vector<vector<array<int64_t, 2>>> dp(n + 1, vector<array<int64_t, 2>>(k + 1, {{0, -INF}}));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + a[i]);
      dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1] + a[i]);
      dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + b[i]);
      if (j > 0)
        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] + b[i]);
    }
  }

  int64_t ans = accumulate(a.begin(), a.end(), int64_t(0));
  for (int i = 1; i <= k; i++) {
    ans = max({ans, dp[n][i][0], dp[n][i][1]});
  }
  cout << ans << '\n';
}
