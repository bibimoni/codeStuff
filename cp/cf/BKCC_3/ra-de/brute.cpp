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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int x = a[i], y = a[j];
      dbg(x, y);
      bool can = true;
      vector<int> used;
      while (can) {
        can = false;
        for (int bi : b) {
          if ((x % bi == 0) && (y % bi == 0)) {
            used.push_back(bi);
            x /= bi;
            y /= bi;
            can = true;
            break;
          }
        }
      }

      dbg(used, x, y);
      ans += x + y;
    }
  }

  cout << ans / 2 << '\n';
}
