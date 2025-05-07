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
  int n;
  cin >> n;
  double a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<double>());
  vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
  dp[0] = vector<double>(n + 1, 1.0);
  vector<vector<double>> p1(n + 1, vector<double>(n + 1, 1.0));
  p1[0] = vector<double>(n + 1, 0.0);
  p1[1][1] = 1.0 - a[1];
  dp[1][1] = a[1];
  for(int t = 1; t <= n; t++) {
    for(int i = 2; i <= n; i++) {
      for(int j = 1; j < i; j++) {
        if(dp[i][t] < dp[j][t] * (1 - a[i]) + a[i] * p1[j][t]) {
          dp[i][t] = dp[j][t] * (1 - a[i]) + a[i] * p1[j][t];
          p1[i][t] = p1[i][j] * (1 - a[i]);
        }
      }
    }
  }
}

