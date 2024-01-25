/**
 * File              : guardmark.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 11.09.2023
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
#define INF           (int) 1e9
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

int dp[1048586] = {}, he[1048586] = {};

signed main() {
  TLE;
  freopen("guard.in", "r", stdin);
  freopen("guard.out", "w", stdout);
  int n, height; cin >> n >> height;
  int h[n], w[n], s[n];
  for(int i = 0; i < n; i++) {
   cin >> h[i] >> w[i] >> s[i];
  }
  int ans = -INF; dp[0] = INF;
  for(int i = 1; i < (1 << n); i++) dp[i] = -INF;
  for(int i = 0; i < (1 << n); i++) {
    if(he[i] >= height) ans = max(ans, dp[i]);
    for(int j = 0; j < n; j++) {
      if(!(i & (1 << j))) {
        dp[i | (1 << j)] = max(dp[i | (1 << j)], min(dp[i] - w[j], s[j]));
        he[i | (1 << j)] = he[i] + h[j];
      }  
    }
  }
  if(ans < 0) cout << "Mark is too tall";
  else cout << ans;
}
