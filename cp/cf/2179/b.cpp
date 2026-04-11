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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += abs(a[i] - a[i + 1]);
    }

    int init = ans;
    for (int i = 0; i < n - 2; i++) {
      int cur = init - abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i + 2]) +
                abs(a[i] - a[i + 2]);
      ans = min(ans, cur);
    }

    ans = min(ans, init - abs(a[n - 1] - a[n - 2]));
    ans = min(ans, init - abs(a[0] - a[1]));

    cout << ans << '\n';
  }
}
