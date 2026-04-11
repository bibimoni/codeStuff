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

    bool first = a[0] == -1, last = a[n - 1] == -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == -1) {
        a[i] = 0;
      }
    }
    if (first) {
      a[0] = a[n - 1];
    } else if (last) {
      a[n - 1] = a[0];
    } else if (last && first) {
      a[0] = a[n - 1] = 0;
    }

    int ans = abs(a[n - 1] - a[0]);
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
}
