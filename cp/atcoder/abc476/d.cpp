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
  int n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  int ans = 0;
  for (int i = 0; i <= m; i++) {
    int need_k = (i > 0 ? (b[i] + k - 1) / k : 0);
    if (need_k > y) {
      break;
    }
    y -= need_k;
    x += need_k * k - b[i];

    int lo = 0, hi = n, ret = 0;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (a[mid] <= x + y * k) {
        lo = mid + 1;
        ret = mid;
      } else {
        hi = mid - 1;
      }
    }

    ans = max(ans, i + ret);
  }

  cout << ans << '\n';
}
