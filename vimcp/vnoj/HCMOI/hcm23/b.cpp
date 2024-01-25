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

const int N = (int) 511, INF = (int) 2e9;
int n, k, d[N], pre[N], dp[N][N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int ans = INF; cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> d[i];
  for(int j = 1; j <= k; j++)
    for(int i = 1; i <= n; i++)
      dp[i][j] = INF;
  int currMax = 0;
  for(int i = 1; i <= n; i++) {
    currMax = max(currMax, d[i]);
    pre[i] = pre[i - 1] + d[i];
    dp[i][0] = currMax * i - pre[i];
  }
  for(int j = 1; j <= k; j++) {
    for(int i = 1; i <= n; i++) {
      currMax = d[i];
      for(int k = i; k >= 1; k--) {
        currMax = max(currMax, d[k]);
        //dbg(currMax, i, k, pre[i] - pre[k - 1]);
        dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + currMax * (i - k + 1) - (pre[i] - pre[k - 1])); 
      }
    }
  }
  for(int j = 0; j <= k; j++) {
    ans = min(ans, dp[n][j]);
  }
  cout << ans;
}


