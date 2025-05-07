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

const int N = 205;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, 0)));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        int curr = (i % 2 == 0 ? 0 : 1);
        curr ^= (j % 2 == 0 ? 0 : 2);
        curr ^= (k % 2 == 0 ? 0 : 3);
        if(i > 0)
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
        if(j > 0)
          dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
        if(k > 0)
          dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
        dp[i][j][k] += (curr == 0);
      }
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << dp[a][b][c] + (d / 2) - 1 << "\n";
  }
}

