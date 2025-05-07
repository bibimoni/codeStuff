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
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n]; vector<set<int>> dp(n);
  for(int i = 0; i < n; i++) cin >> a[i], dp[i].insert(a[i]);
  for(int i = 1; i < n; i++) {
    int idx = i, currMax = dp[i].size();
    for(int j = 0; j < i; j++) {
      if(a[i] > a[j] && currMax < (int) dp[j].size() + 1) {
        idx = j;
        currMax = dp[j].size() + 1;
      }
    }
    dp[i].insert(all(dp[idx]));
  }
  dbg(dp); int ans = 0;
  vector<set<int>> dpRev(n);
  for(int i = 0; i < n; i++) dpRev[i].insert(a[i]);
  for(int i = n - 2; i >= 0; i--) {
    int idx = i, currMax = dpRev[i].size();
    for(int j = n - 1; j > i; j--) {
      if(a[i] > a[j] && currMax < (int) dpRev[j].size() + 1) {
        idx = j;
        currMax = dpRev[j].size() + 1;
      }
    }
    dpRev[i].insert(all(dpRev[idx])); 
  }
  dbg(dp, dpRev);
  for(int i = 0; i < n; i++) {
    dp[i].insert(all(dpRev[n - i - 1]));
    ans = max(ans, (int) dp[i].size());
  }
  dbg(dp)
  //cout << *max_element(all(dp));
  cout << ans;
}

