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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == 67) {
        ok = true;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
