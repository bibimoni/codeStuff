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
    int a, b;
    cin >> a >> b;
    int ans = ((a + b) % 2 == 0 ? a + b : -1);
    int cnt = 0;
    int tb = b;
    while (tb % 2 == 0) {
      tb /= 2;
      cnt += 1;
    }
    dbg(cnt);
    for (int i = 0, cur = 1; i <= cnt; i++, cur *= 2) {
      int k = b / cur;
      int na = a * k;
      int nb = cur;
      dbg(k, na, nb);
      if ((na + nb) % 2 == 0) {
        ans = max(ans, na + nb);
      }
    }
    cout << ans << '\n';
  }
}
