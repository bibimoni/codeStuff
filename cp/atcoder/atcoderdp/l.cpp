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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n + 1]; vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][i] = a[i];
  }
  for(int i = n; i >= 0; i--) {
    for(int j = i + 1; j <= n; j++) {
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
      dbg(i, j, dp[i][j]);
    }
  }
  cout << dp[1][n];
}


