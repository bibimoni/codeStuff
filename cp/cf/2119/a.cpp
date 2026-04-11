/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (b == a - 1) {
      cout << ((a ^ 1) == b ? y : -1) << '\n';
    } else {
      if (a > b) {
        cout << "-1\n";
        continue;
      }
      int ans = 0;
      while (a < b) {
        if (a % 2 == 0) {
          ans += min(x, y);
        } else {
          ans += x;
        }
        a += 1;
      }
      cout << ans << '\n';
    }
  }
}
