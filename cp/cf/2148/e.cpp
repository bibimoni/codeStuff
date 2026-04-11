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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> mx(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx[a[i]] += 1;
    }

    bool ok = false;
    for (int i = 1; i <= n; i++) {
      if (mx[i] % k != 0) {
        ok = true;
      }
      mx[i] /= k;
    }

    if (ok) {
      cout << "0\n";
      continue;
    }

    int ans = 0;
    vector<int> cnt(n + 1);
    for (int i = 0, j = 0; i < n; i++) {
      cnt[a[i]] += 1;
      while (j <= i && cnt[a[i]] > mx[a[i]]) {
        cnt[a[j]] -= 1;
        j += 1;
      }

      ans += i - j + 1;
    }

    cout << ans << '\n';
  }
}
