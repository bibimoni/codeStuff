// time-limit: 3000
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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if(n == 1) {
      cout << a[1] << '\n';
      continue;
    }
    const int INF = (int) 1e18;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    for(int i = 0; i <= k; i++)
      dp[0][i] = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= k; j++) {
        dp[i][j] = dp[i - 1][j] + a[i];
        int curr = a[i];
        for(int t = 0; i - t - 1 >= 0 && t <= j; t++) {
          dp[i][j] = min(dp[i][j], dp[i - t - 1][j - t] + curr * (t + 1));
          curr = min(a[i - t - 1], curr);
        }
      }
    }
    int ans = INF;
    for(int i = 0; i <= k; i++) {
      ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
  }
}


