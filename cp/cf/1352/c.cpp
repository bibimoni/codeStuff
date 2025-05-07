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
    int n, k; cin >> n >> k;
    int ans = 0, l = 1, r = 2e9;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(mid - (mid / n) >= k) ans = mid, r = mid - 1;
      else l = mid + 1;
    }
    cout << ans << '\n';
  }
}


