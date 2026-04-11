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
    int n, h;
    cin >> n >> h;
    int mn = h, mx = h, curt = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int t, l, u;
      cin >> t >> l >> u;
      int nmx = mx + (t - curt);
      int nmn = max(1, mn - (t - curt));
      if (nmx < l || nmn > u) {
        ok = false;
      }
      mn = max(l, nmn);
      mx = min(u, nmx);
      curt = t;
    }

    cout << (ok ? "Yes\n" : "No\n");
  }
}
