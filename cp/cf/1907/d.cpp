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
    int n; cin >> n;
    int lt[n + 1], rt[n + 1];
    int bound = 0;
    for(int i = 1; i <= n; i++) cin >> lt[i] >> rt[i], bound = max(bound, rt[i]);
    int l = 0, r = bound, ans;
    while(l <= r) {
      int mid = (l + r) >> 1;
      bool possible = true;
      int m = 0, M = 0;
      for(int i = 1; i <= n; i++) {
        dbg(m, M);
        m = max(m - mid, lt[i]);
        M = min(M + mid, rt[i]);
        dbg(m, M);
        if(m > M) {
          possible = false;
          break;
        }
        //m = max(m - mid, 0ll);
      }
      dbg(mid, possible);
      if(possible) {
        r = mid - 1;
        ans = mid;
      }
      else {
        l = mid + 1;
      }
    }
    cout << ans << "\n";
  }
}


