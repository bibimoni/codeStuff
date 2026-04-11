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
    int x, y, z;
    cin >> x >> y >> z;
    auto g = [&](int v, int b) -> int { return (v >> b) & 1; };
    bool ok = true;
    for (int i = 30; i >= 0; i--) {
      int cnt = g(x, i) + g(y, i) + g(z, i);
      ok &= (cnt != 2);
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
