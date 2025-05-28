/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <cmath>
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

    int ans = 0;
    int sum_mn = 0;
    for (int i = 1; i < n; i++) {
      int mn = a[i];
      for (int j = i; j >= 0; j--) {
        mn = min(mn, a[j]);
        sum_mn += mn;
        ans += a[i] + a[j] - 2 * mn;
      }
    }
    dbg(sum_mn);
    cout << ans << '\n';
  }
}
