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
    int a;
    cin >> a;
    int c = 1;
    int lo = 1, hi = 1e9;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (mid * mid - a - 1 > 0) {
        c = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    cout << "1 " << c * c - a - 1 << '\n';
  }
}
