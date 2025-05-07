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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    int ans = 0;
    for(int i = 1; i <= x; i++) {
      for(int j = 1; j <= y; j++) {
        if(i * j > k)
          continue;
        if(k % (i * j) == 0) {
          int m = k / (i * j);
          ans = max(ans, (x - i + 1) * (y - j + 1) * (z - m + 1));
        }
      }
    }
    cout << ans << '\n';
  }
}


