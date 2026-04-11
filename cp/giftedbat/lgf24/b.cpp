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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }

  const int inf = 1e18;
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(3, vector<int>(2, -inf)));

  auto f3 = [&](int x) -> int { return (x + (3 * int(2e9))) % 3; };

  for (int i = 1; i <= n; i++) {
    dp[i][0][1] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + a[i]);
      if (i <= 2) {
        dp[i][f3(a[i])][0] = max(dp[i][f3(a[i])][0], a[i]);
      } else {
        dp[i][f3(a[i] + j)][0] =
            max(dp[i][f3(a[i] + j)][0], dp[i - 2][j][1] + a[i]);
      }
    }

    for (int j = 0; j < 3; j++) {
      dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1]);
      dp[i][f3(a[i] + j)][1] = max(dp[i][f3(a[i] + j)][1], dp[i][j][0]);
    }
  }
  cout << dp[n][0][1];
}
