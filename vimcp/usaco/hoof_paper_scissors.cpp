/**
 * File              : hoof_paper_scissors.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 31.07.2023
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
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  int n, k; cin >> n >> k;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    char x; cin >> x;
    if(x == 'H') a[i] = 0;
    if(x == 'S') a[i] = 1;
    if(x == 'P') a[i] = 2;
  }
  vector<vector<vector<int>>> dp(n + 3, vector<vector<int>>(k + 3, vector<int>(3, -1)));
  dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 0;
  for(int i = 1; i <= n; i++) {
    dp[i][0][a[i]]++;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= k; j++) {
      dp[i][j][0] = max(dp[i - 1][j][0] + (0 == a[i]), dp[i][j][0]);
      dp[i][j][1] = max(dp[i - 1][j][1] + (1 == a[i]), dp[i][j][1]);
      dp[i][j][2] = max(dp[i - 1][j][2] + (2 == a[i]), dp[i][j][2]);
      if(j == 0) continue;
      dp[i][j][0] = max({dp[i - 1][j - 1][1] + (0 == a[i]), dp[i - 1][j - 1][2] + (0 == a[i]), dp[i][j][0]});
      dp[i][j][1] = max({dp[i - 1][j - 1][0] + (1 == a[i]), dp[i - 1][j - 1][2] + (1 == a[i]), dp[i][j][1]});
      dp[i][j][2] = max({dp[i - 1][j - 1][0] + (2 == a[i]), dp[i - 1][j - 1][1] + (2 == a[i]), dp[i][j][2]});
    }
  }
  int ans = -1;
  for(int i = 0; i <= k; i++) {
    for(int g = 0; g < 3; g++)
    ans = max({ans, dp[n][i][g]});
  }
  cout << ans;
}

