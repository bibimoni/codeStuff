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
  int h, w;
  cin >> h >> w;
  int q;
  cin >> q;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int r;
      cin >> r;
      cout << r * w;
      h -= r;
    } else {
      int c;
      cin >> c;
      cout << c * h;
      w -= c;
    }
    cout << '\n';
  }
}
