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

    sort(a.begin(), a.end());

    int lo = 0, hi = 1e18, ret = 0;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      auto b = a;
      for (int i = 0; i < n; i++) {
        b[i] = min(b[i], mid);
      }
      int cnt = 0, cur = 0;
      for (int i = 0; i < n; i++) {
        int nxt = min(mid - cur, b[i]);
        cur += nxt;
        b[i] -= nxt;
        if (cur == mid) {
          cnt += 1;
          cur = 0;
        }

        cur += b[i];
      }

      if (cnt < k) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
        ret = mid;
      }
    }

    cout << ret << '\n';
  }
}
