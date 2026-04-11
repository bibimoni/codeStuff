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
    int n;
    cin >> n;
    int ans = 0, i = 0;
    while (n - 2 * i >= 0) {
      ans += (n - 2 * i) % 4 == 0;
      i += 1;
    }
    cout << ans << '\n';
  }
}
