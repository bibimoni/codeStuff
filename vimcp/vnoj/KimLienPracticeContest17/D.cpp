/**
 * File              : D.cpp
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
  int n, W; cin >> n >> W;
  int w[n + 1], v[n + 1], dp[n + 1][W + 1];
  for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
  for(int i = 1; i <= n; i++) dp[i][0] = 0;
  for(int i = 1; i <= W; i++) dp[0][i] = 0;
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= W; j++) {
      dp[i][j] = dp[i - 1][j];
      if(j - w[i] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[n][W];
}

