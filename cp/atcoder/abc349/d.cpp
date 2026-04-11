/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <cstdint>
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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int64_t, int64_t> l, r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    r[a[i]] += 1;
  }

  int64_t ans = 0;
  for (int i = 1; i <= n; i++) {
    r[a[i]] -= 1;
    if (a[i] % 5 == 0) {
      ans += l[(int64_t(a[i]) * 7) / 5] * l[(int64_t(a[i]) * 3) / 5];
      ans += r[(int64_t(a[i]) * 7) / 5] * r[(int64_t(a[i]) * 3) / 5];
    }
    l[a[i]] += 1;
  }

  cout << ans << '\n';
}
