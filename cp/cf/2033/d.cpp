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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    map<int, int> mp;
    mp[0] = 0;
    vector<int> dp(n + 1, 0);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
      cur += a[i];
      dp[i] = dp[i - 1];
      if (mp.count(cur)) {
        dp[i] = max(dp[i], dp[mp[cur]] + 1);
      }
      mp[cur] = i;
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}


