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
  int n;
  cin >> n;
  vector<int> l(n);
  vector<int> pre;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    cur += l[i];
    pre.push_back(cur);
  }

  int lo = 0, hi = n - 1, ans = 1e15;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    int m = pre[mid];
    bool ok = true;
    cur = 0;
    for (int i = 0; i < n; i++) {
      if (cur == 0) {
        if (l[i] > m) {
          ok = false;
          break;
        }
      } else {
        // k * mid >= cur
        int k = (m + cur - 1) / m;
        dbg(m, l[i], cur, k);
        if (k * m > cur && k * m < cur + l[i]) {
          ok = false;
          dbg(ok);
          break;
        }
      }
      cur += l[i];
    }

    if (ok) {
      hi = mid - 1;
      ans = m;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans;
}
