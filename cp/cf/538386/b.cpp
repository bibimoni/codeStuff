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
    int n, b, c;
    cin >> n >> b >> c;
    if (b == 0) {
      if (c == 0) {
        cout << "-1\n";
      } else {
        cout << n - 1 << '\n';
      }
      continue;
    }
    int l = 0, r = n, ret = -1;
    while (l <= r) {
      int m = (l + r) >> 1;
      int rem = n - m;
      int t = (((rem - 1) > (2e18) / (b - 1)) ? 2e18 : (rem == 0 ? 1 : (rem - 1) * (b - 1) + c));
      dbg(t, rem, m);
      if (m >= t) {
        r = m - 1;
        ret = m;
      } else {
        l = m + 1;
      }
    }
    cout << ret << '\n';
  }
}


