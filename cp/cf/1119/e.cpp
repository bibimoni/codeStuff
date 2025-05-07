// time-limit: 3000
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int p = 0;
  for (int i = n - 1; i >= 0; i--) {
    p += a[i] / 2;
    if (a[i] % 2 == 1 && p > 0) {
      p -= 1;
      ans += 1;
    }
  }
  ans += 2 * p / 3;
  cout << ans << '\n';
}
