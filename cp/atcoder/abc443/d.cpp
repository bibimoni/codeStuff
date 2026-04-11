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
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
      cin >> r[i];
    }

    vector b = r;
    for (int i = 0; i + 1 < n; i++) {
      b[i + 1] = min(b[i + 1], b[i] + 1);
    }
    for (int i = n - 1; i > 0; i--) {
      b[i - 1] = min(b[i - 1], b[i] + 1);
    }

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      ans += r[i] - b[i];
    }
    cout << ans << '\n';
  }
}
