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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  vector<array<int64_t, 3>> dp(n + 1);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + a[i];
    if (i > 1) {
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];
    }
    if (i > 2) {
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + c[i];
    }
  }

  cout << dp[n][2];
}
