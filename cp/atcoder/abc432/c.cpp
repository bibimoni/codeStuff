/**
 * Author: distiled
 */
#include <algorithm>
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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  int d = *min_element(a.begin(), a.end()) * y;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    int small = a[i] * y - d;
    if (small % (y - x) != 0) {
      ok = false;
      break;
    }
    if (a[i] - small / (y - x) < 0) {
      ok = false;
      break;
    }
    ans += a[i] - small / (y - x);
  }

  cout << (ok ? ans : -1);
}
