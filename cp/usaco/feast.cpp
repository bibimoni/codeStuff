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
  freopen("feast.in", "r", stdin);
  freopen("feast.out", "w", stdout);
  int t, a, b;
  cin >> t >> a >> b;

  vector<array<int, 2>> dp(t + 1, array<int, 2>{0, 0});
  dp[0][0] = 1;
  for (int i = 1; i <= t; i++) {
    if (i >= a) {
      dp[i][0] = max(dp[i - a][0], dp[i][0]);
    }
    if (i >= b) {
      dp[i][0] = max(dp[i - b][0], dp[i][0]);
    }
  }
  for (int i = 1; i <= t; i++) {
    vector<int> val{i * 2, i * 2 + 1};
    for (int k : val) {
      if (k <= t) {
        dp[i][1] = max(dp[k][0], dp[i][1]);
      }
    }
    if (i >= a) {
      dp[i][1] = max(dp[i - a][1], dp[i][1]);
    }
    if (i >= b) {
      dp[i][1] = max(dp[i - b][1], dp[i][1]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= t; i++) {
    if (max(dp[i][1], dp[i][0])) {
      ans = i;
    }
  }
  cout << ans;
}

