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
#define all(x)         x.begin(), x.end()
const int N = (int) 2e5;
int dp[23];
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n + 1], ans = 0;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) {
    if(i - 6 >= 1) {
      dp[a[i - 6] % 23]++;
      ans += dp[a[i] % 23];
    }
  } 
  cout << ans;
}


