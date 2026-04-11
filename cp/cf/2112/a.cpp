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
    int a, x, y;
    cin >> a >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    bool ok = false;
    for (int b = x - 1; b <= y + 1; b++) {
      if (b == a) {
        continue;
      }
      ok |= abs(a - x) > abs(b - x) && abs(a - y) > abs(b - y);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
