/**
 * File              : A.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 09.08.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
#include <cstdio>
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
  freopen("PHANTICH.INP", "r", stdin);
  freopen("PHANTICH.OUT", "w", stdout); 
  int n; cin >> n;
  int dp[n + 1] = {0};
  dp[1] = dp[0] = 1;
  for(int j = 1; j <= n; j++) {
    for(int i = 2; i <= n; i++) {
      if(i - j >= 0) {
        dp[i] += dp[i - j];
      }
    }
  } 
  cout << dp[n];
}

