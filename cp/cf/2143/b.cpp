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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
      cin >> b[i];
    }

    sort(b.begin(), b.end());
    sort(a.begin(), a.end(), greater<int>());
    int cur = 0, ans = 0;
    for (int i = 0; i < k; i++) {
      if (cur + b[i] - 1 < n) {
        for (int j = cur; j < cur + b[i] - 1; j++) {
          ans += a[j];
        }
        cur += b[i];
      }
    }

    for (int i = cur; i < n; i++) {
      ans += a[i];
    }

    cout << ans << '\n';
  }
}
