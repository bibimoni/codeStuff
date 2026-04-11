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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto getd = [&](int x) -> int {
    int ret = 0;
    while (x) {
      ret += 1;
      x /= 10;
    }
    return ret;
  };

  const int D = 10;
  array<map<int, int>, D + 1> mul;
  for (int d = 0; d <= D; d++) {
    mul[d] = map<int, int>();
  }

  for (int i = 0; i < n; i++) {
    int64_t pwr10 = 10;
    for (int d = 1; d <= D; d++, pwr10 *= 10) {
      int64_t val = int64_t(a[i] % m) * (pwr10 % m);
      mul[d][val % m] += 1;
    }
  }

  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int dnum = getd(a[i]);
    ans += mul[dnum][(m - (a[i] % m)) % m];
  }

  cout << ans << '\n';
}
