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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto count = [&](int x, int64_t val) -> int {
    int lo = 0, hi = n - 1, idx = n;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (a[mid] >= x) {
        hi = mid - 1;
        idx = mid;
      } else {
        lo = mid + 1;
      }
    }

    lo = idx, hi = n - 1;
    int ret = 0;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (a[mid] <= val) {
        lo = mid + 1;
        ret = mid - idx + 1;
      } else {
        hi = mid - 1;
      }
    }

    return ret;
  };

  sort(a.begin(), a.end());

  while (q--) {
    int x, y;
    cin >> x >> y;
    int64_t lo = 0, hi = 1e18;
    int64_t ans = y + n;
    while (lo <= hi) {
      int64_t mid = (lo + hi) >> 1;
      int64_t tmp = mid - count(x, mid);
      if (tmp >= y + x - 1) {
        hi = mid - 1;
        if (tmp == y + x - 1)
          ans = mid;
      } else {
        lo = mid + 1;
      }
    }

    cout << ans << '\n';
  }
}
