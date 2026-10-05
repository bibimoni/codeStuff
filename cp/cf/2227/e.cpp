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

    int lim = n + 1;
    int64_t add = 0;
    vector<int64_t> cnt(n + 2);
    for (int i = n - 1; i >= 0; i--) {
      lim = min(a[i], lim);
      cnt[1] += 1;
      cnt[lim + 1] -= 1;
      add += a[i] - lim;
    }

    for (int i = 1; i <= n; i++) {
      cnt[i] += cnt[i - 1];
    }

    int64_t ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      int len = n - i;
      if (cnt[a[i]] >= len) {
        ans = max(ans, cnt[a[i]] - len);
      }
    }

    ans += add;
    cout << ans << '\n';
  }
}
