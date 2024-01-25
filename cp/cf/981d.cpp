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
  int n, k; cin >> n >> k;
  int a[n + 1]; a[0] = 0;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 2; i <= n; i++) a[i] += a[i - 1];
  int ans = 0;
  auto check = [&] (int mask) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++) {
      for(int j = 1; j <= k; j++) {
        for(int id = i; id <= n; id++) {
          if(dp[i][j - 1]) dp[id][j] |= (((a[id] - a[i]) & mask) == mask);
        } 
      }
    }
    return dp[n][k];
  };
  for(int j = 60; j >= 0; j--) {
    if(check(ans + (1ll << j))) {
      ans += (1ll << j);
    }
  }
  cout << ans;
}

