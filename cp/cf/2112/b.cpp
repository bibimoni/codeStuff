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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 2) {
      cout << (abs(a[0] - a[1]) <= 1 ? "0\n" : "-1\n");
      continue;
    }
    int ans = -1;
    for (int i = 0; i + 2 < n; i++) {
      if (ans == 0) {
        break;
      }
      int l1 = min(a[i], a[i + 1]);
      int r1 = max(a[i], a[i + 1]);

      int l2 = min(a[i + 2], a[i + 1]);
      int r2 = max(a[i + 2], a[i + 1]);

      if (r1 - l1 <= 1 || r2 - l2 <= 1) {
        ans = 0;
      } else if ((l1 <= a[i + 2] && a[i + 2] <= r1) ||
                 (l2 <= a[i] && a[i] <= r2)) {
        ans = 1;
      }
    }
    cout << ans << '\n';
  }
}
