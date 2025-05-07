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

const int MOD = 998244353;
const int OFFSET = 1e5, A = 2e5;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector dp(A, int(0));
  dp[a[2] + OFFSET] = 1;
  for (int i = 3; i <= n; i++) {
    vector<int> ndp(A, int(0));
    for (int y = 0; y < A; y++) {
      if (dp[y] == 0) {
        continue;
      }
      (ndp[a[i] + y] += dp[y]) %= MOD;
      if (y - OFFSET == 0) {
        continue;
      }
      (ndp[a[i] - y + 2 * OFFSET] += dp[y]) %= MOD;
    }
    swap(dp, ndp);
  }
  int ans = 0;
  for (int i = 0; i < int(dp.size()); i++) {
    (ans += dp[i]) %= MOD;
  }
  cout << ans;
}

