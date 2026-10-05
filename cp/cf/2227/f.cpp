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

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      ans -= 1ll * (i + 1) * a[i];
    }

    vector<int> cnt(n + 2);
    for (int i = 0; i < n; i++) {
      cnt[1] += 1;
      cnt[a[i] + 1] -= 1;
    }

    for (int i = 1; i <= n; i++) {
      cnt[i] += cnt[i - 1];
    }

    int col = n;
    int64_t mx = 0;
    for (int i = 0; i < n; i++) {
      if (mx < i - (n - cnt[a[i]])) {
        mx = i - (n - cnt[a[i]]);
        col = i;
      }
    }

    if (col != n) {
      cnt[a[col]] -= 1;
      ans += col + 1;
    }

    for (int i = 1; i <= n; i++) {
      int len = n - cnt[i];
      int64_t sub = 1ll * len * (len + 1) / 2;
      ans += 1ll * n * (n + 1) / 2 - sub;
    }

    cout << ans << "\n";
  }
}
