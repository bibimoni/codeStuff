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
  int n, c;
  cin >> n >> c;
  int prev = -int(1e9);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x; 
    cin >> x;
    if (x - prev >= c) {
      ans += 1;
      prev = x;
    }
  }
  cout << ans;
}


