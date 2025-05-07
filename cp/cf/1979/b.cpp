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
    int x, y;
    cin >> x >> y;
    int ans = 0, curr = 0;
    for(int j = 0; j < 35; j++) {
      if(!x && !y)
        break;
      if((x & 1) != (y & 1)) {
        ans = max(ans, curr);
        curr = 0;
        break;
      }
      else {
        curr++;
      }
      x >>= 1;   
      y >>= 1;
    }
    cout << (1ll << ans) << '\n';
  }
}


