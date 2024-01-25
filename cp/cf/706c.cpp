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
  int n; cin >> n;
  int c[n + 1];
  string a[n + 1], b[n + 1];
  for(int i = 1; i <= n; i++) cin >> c[i];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    reverse(b[i].begin(), b[i].end());
  }
  vector<array<int, 2>> dp(n + 1, array<int, 2>({INF, INF}));
  dp[0][1] = dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    if(b[i - 1] <= a[i]) dp[i][0] = min(dp[i - 1][1], dp[i][0]);
    if(a[i - 1] <= b[i]) dp[i][1] = min(dp[i - 1][0] + c[i], dp[i][1]);
    if(a[i - 1] <= a[i]) dp[i][0] = min(dp[i - 1][0], dp[i][0]);
    if(b[i - 1] <= b[i]) dp[i][1] = min(dp[i - 1][1] + c[i], dp[i][1]);
  }
  int ans = min(dp[n][1], dp[n][0]);
  cout << (ans == INF ? -1 : ans);
}

