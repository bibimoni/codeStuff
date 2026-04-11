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
  int l, r, d, u;
  cin >> l >> r >> d >> u;
  int64_t ans = 0;
  for (int x = l; x <= r; x++) {
    for (int y = d; y <= u; y++) {
      ans += int(max(abs(x), abs(y)) % 2 == 0);
    }
  }
  cout << ans << '\n';
}
