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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    const int INF = 1e9;
    vector<array<int, 3>> dp(n + 1, array<int, 3>{INF, INF, INF});
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      dp[i + 1][0] = min(dp[i][0] + int(s[i] == '1'), dp[i + 1][0]);
      dp[i + 1][1] = min({dp[i + 1][1], dp[i][1] + int(s[i] == '0'),
                          dp[i][0] + int(s[i] == '0')});
      dp[i + 1][2] =
          min({dp[i + 1][2], dp[i][2] + int(s[i] == '1'),
               dp[i][1] + int(s[i] == '1'), dp[i][0] + int(s[i] == '1')});
    }
    dbg(s, dp);
    cout << min(dp[n][1], dp[n][2]) << '\n';
  }
}
