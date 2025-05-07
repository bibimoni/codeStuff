// time-limit: 3000
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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  vector<int> dp(m + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    dp[a[i].second] = max(dp[a[i].second], a[i].first);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    dp[i] = max(dp[i - 1], dp[i]);
    ans += i - dp[i];
  }
  cout << ans << '\n';
}


