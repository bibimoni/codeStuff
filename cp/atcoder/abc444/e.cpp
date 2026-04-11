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
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> f(n + 1, n - 1);
  for (int i = n - 2; i >= 0; i--) {
    if (abs(a[i] - a[i + 1]) < d) {
      f[i] = i;
    } else {
      f[i] = f[i + 1];
    }
  }

  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    dbg(f[i], i);
    ans += f[i] - i + 1;
  }
  cout << ans << '\n';
}
