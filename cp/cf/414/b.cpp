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
  int n, k;
  cin >> n >> k;

  const int mod = int(1e9 + 7);
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  dp[0][0] = 1;

  vector<vector<int>> divs(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      divs[j].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
  }

  dbg("hi");
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      for (int div : divs[i]) {
        (dp[i][j] += dp[div][j - 1]) %= mod;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    (ans += dp[i][k]) %= mod;
  }
  cout << ans << '\n';
}
