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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  // vector a(n, 0), b(n, 0);
  int ans = 0;
  int ca = 0, cb = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (max(ca + x, cb) > max(ca, cb + y)) {
      cb += y;
    } else {
      ca += x;
    }
  }
  ans = max(ca, cb);

  cout << ans << '\n';
}
