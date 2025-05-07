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
    int lt, rt;
    cin >> lt >> rt;
    int l = 1, r = 1e9, ret = 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (lt + (m * (m + 1) / 2) <= rt) {
        l = m + 1;
        ret = m + 1;
      } else {
        r = m - 1;
      }
    }
    cout << ret << '\n';
  }
}


