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
    int n;
    cin >> n;
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      c1 += int(x == -1);
      c0 += int(x == 0);
    }
    if (c1 % 2 == 0) {
      cout << c0 << '\n';
    } else {
      cout << c0 + 2 << '\n';
    }
  }
}
