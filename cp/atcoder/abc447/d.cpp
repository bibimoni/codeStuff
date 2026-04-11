/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <cmath>
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
  string s;
  cin >> s;
  int ca = 0, cb = 0, ans = 0;
  for (char c : s) {
    if (c == 'A') {
      ca += 1;
    } else if (c == 'B') {
      if (ca > 0) {
        ca -= 1;
        cb += 1;
      }
    } else {
      if (cb > 0) {
        cb -= 1;
        ans += 1;
      }
    }
  }

  cout << ans;
}
