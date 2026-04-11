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
  int n, h, m;
  cin >> n >> h >> m;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  const int INF = 1e9;
  vector<vector<int>> dp(n + 1, vector<int>(h + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= h; w++) {
      if (w >= a[i]) {
        dp[i][w] = min(dp[i][w], dp[i - 1][w - a[i]]);
      }
      if (dp[i - 1][w] + b[i] <= m) {
        dp[i][w] = min(dp[i][w], dp[i - 1][w] + b[i]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= h; j++) {
      if (dp[i][j] != INF) {
        ans = i;
      }
    }
  }
  cout << ans;
}
