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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int red, green;
  cin >> red >> green;
  int h = (int) ((-1.0 + sqrt(1 + 8 * (red + green))) / 2.0);
  //dp[i][j] = dp[i - 1][j] + dp[i - 1][j - thislevel]
  vector<vector<int>> dp(h + 1, vector<int>(red + 1, 0));
  // dp[1][1] = (red >= 1), dp[1][0] = (green >= 1);
  dp[0] = vector<int>(red + 1, 1);
  int p = 0;
  for(int i = 1; i <= h; i++) {
    p += i;
    for(int r = 0; r <= red; r++) {
      if(p - r <= green && p - r >= 0) {
        dp[i][r] += dp[i - 1][r];
      }
      if(r - i >= 0 && p - (r - i) <= green && p - (r - i) >= 0)
        dp[i][r] += dp[i - 1][r - i];
    }
  }
  dbg(dp);
  cout << dp[h][red];
}

