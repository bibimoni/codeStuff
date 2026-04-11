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
    int x;
    cin >> x;
    int tx = x, pwr = 1;
    while (tx) {
      pwr *= 10;
      tx /= 10;
    }

    // int y = -(x + 1 - pwr);
    int y = x * (2 - 10) / (-1);
    assert((x * pwr + y) % (x + y) == 0);
    cout << y << '\n';
  }
}
