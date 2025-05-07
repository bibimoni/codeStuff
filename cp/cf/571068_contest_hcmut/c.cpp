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

const int N = 4e3 + 5;
int a[N];
int dp[N][N], mx[N][N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("gift.inp", "r", stdin);
  // freopen("gift.out", "w", stdout);
  int n, d;
  cin >> n >> d;
  for (int i = 1; i <= n * 2; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 1; j <= n * 2; j++) {
      dp[i][j] = 0;
      mx[i][j] = 0;
    }
  }
  int ans = 0;
  for (int i = 2; i <= 2 * n; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (j + 1 == i) {
        dp[j][i] = max(dp[j][i], int(abs(a[i] - a[j]) <= d)); 
      } else {
        dp[j][i] = max({dp[j][i], dp[j + 1][i - 1] + int(abs(a[i] - a[j]) <= d), dp[j + 1][i], dp[j][i - 1]});
      }
      ans = max(ans, dp[j][i]);
    }
  }
  cout << ans << '\n';
}


