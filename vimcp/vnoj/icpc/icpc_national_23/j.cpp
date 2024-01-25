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
const int MOD = 998244353;

int dp[20][20];

int add(int a, int b) {
  a += b;
  if(a >= MOD) a -= MOD;
  if(a < 0) a += MOD;
  return a;
}

int mul(int a, int b) {
  return (a % MOD * b % MOD) % MOD;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  for(int i = 0, x; i < n; i++) cin >> x;
  dp[1][1] = 1;
  for(int i = 2; i <= n; i++) {
    for(int j = 2; j <= i; j++) {
      dp[i][j] = 0;
      for(int k = j - 1; k <= i; k++) {
        dp[i][j] = add(dp[i][j], dp[i - 1][k]);
      } 
      if(j >= 3) dp[i][j] = mul(dp[i][j], (1 << (j - 2)));
    }
  }
  int res = 0;
  for(int i = 1; i <= n; i++) res = add(res, dp[n][i]);
  cout << res;
}



