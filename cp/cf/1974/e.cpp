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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int m, x;
    cin >> m >> x;
    vector<int> c(m + 1), h(m + 1);
    int tH = 0;
    for(int i = 1; i <= m; i++) {
      cin >> c[i] >> h[i];
      tH += h[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(tH + 1, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++) {
      for(int j = 0; j <= tH; j++) {
        dp[i][j] = dp[i - 1][j];
        if(j >= h[i] && (i - 1) * x - dp[i - 1][j - h[i]] >= c[i]) {
          dp[i][j] = min(dp[i - 1][j - h[i]] + c[i], dp[i][j]);
        }
      }
    }
    int ans = 0;
    for(int j = tH; j >= 0; j--) {
      if(dp[m][j] <= (m - 1) * x) {
        ans = max(ans, j);
      }
    }
    cout << ans << '\n';
  }
}


