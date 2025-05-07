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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    //[....]xy[....m]
    //x[....][...m]x
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
      if(dp[i - 1] && i + a[i] <= n) {
        dp[i + a[i]] = 1;
      }
      if(i - a[i] - 1 >= 0 && dp[i - a[i] - 1]) {
        dp[i] = 1;
      }
    }
    cout << (dp[n] ? "YES\n" : "NO\n");
  }
}


