/**
 * File              : F.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 09.08.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

signed main() {
  TLE;
  int m, n; cin >> m >> n;
  int a[m + 1][n + 1];
  int dp[m + 1][n + 1];
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> a[i][j];
      dp[i][j] = -INF;
    }
  }
  for(int j = 0; j <= n; j++) {
    for(int i = 0; i <= m; i++) {
      if(i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if(i >= 2) dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i][j]);
      if(i <= m - 1) dp[i][j] = max(dp[i + 1][j - 1] + a[i][j], dp[i][j]);
      dp[i][j] = max(dp[i][j - 1] + a[i][j], dp[i][j]);
    }
  }
  int ans = -INF;
  for(int i = 1; i <= m; i++) {
    ans = max(dp[i][n], ans);
  }
  cout << ans;
}


