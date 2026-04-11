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
    int n, m;
    cin >> n >> m;
    int pos = 0, time = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      ans += a - time - 1;
      if (time % 2 == a % 2) {
        ans += (b == pos);
      } else {
        ans += (b != pos);
      }
      pos = b;
      time = a;
    }
    ans += m - time;
    cout << ans << '\n';
  }
}
