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
  int cur = 0, vol = 0;
  int q;
  cin >> q;
  while (q--) {
    int a;
    cin >> a;
    if (a == 1) {
      vol += 1;
    } else if (a == 2) {
      vol -= min(1, vol);
    } else {
      cur ^= 1;
    }
    cout << (vol >= 3 && cur ? "Yes\n" : "No\n");
  }
}
