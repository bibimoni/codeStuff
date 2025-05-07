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
    int ans = ceil(y / 2.0);
    if(y & 1) {
      x -= min(x, 11ll);
    }
    x -= min((ans - (y & 1)) * 7, x);
    ans += ceil(x / 15.0);
    cout << ans << '\n';
  }
}


