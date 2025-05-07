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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;
    c = " " + c;
    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        if (i == 0) {
          dp[i][j] = min(dp[i][j], (int)dp[i][j - 1] + (c[i + j] != b[j]));
        } else if (j == 0) {
          dp[i][j] = min(dp[i][j], (int)dp[i - 1][j] + (c[i + j] != a[i]));          
        } else {
          dp[i][j] = min(dp[i - 1][j] + (c[i + j] != a[i]), dp[i][j - 1] + (c[i + j] != b[j]));
        }
      }
    }
    cout << dp[n][m] << '\n';
  }
}


