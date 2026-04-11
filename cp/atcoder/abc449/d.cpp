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
  int l, r, d, u;
  cin >> l >> r >> d >> u;
  auto inter = [&] (int x, int y, int u, int v) -> pair<int, int> {
    int mn = max(x, u);
    int mx = min(y, v);
    return {mn, mx};
  };
  auto cnt_inter = [&](int x, int y, int u, int v) -> int {
    auto [mn, mx] = inter(x, y, u, v);
    if (mn > mx) {
      return 0;
    }
    return mx - mn + 1;
  };
  auto cnt_even = [&](int l, int r) -> int {
    if (r < l) {
      return 0;
    }
    auto [nl, nr] = inter(l, r, d, u);
    int tot = nr - nl + 1;
    int ret = tot / 2;
    if (tot % 2 != 0 && (nl % 2 == 0 || nr % 2 == 0)) {
      ret += 1;
    }
    return ret;
  };
  int64_t ans = 0;
  for (int i = l; i <= r; i++) {
    if (abs(i) % 2 == 0) {
      int x = -abs(i), y = abs(i);
      ans += cnt_inter(d, u, x, y);
      int nx = -abs(i) - 1, ny = abs(i) + 1;
      ans += cnt_even(d, nx) + cnt_even(ny, u);
    } else {
      int nx = -abs(i) - 1, ny = abs(i) + 1;
      ans += cnt_even(d, nx) + cnt_even(ny, u);
    }
  }

  cout << ans << '\n';
}
