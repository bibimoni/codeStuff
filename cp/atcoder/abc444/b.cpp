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
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cur = 0, j = i;
    while (j) {
      cur += j % 10;
      j /= 10;
    }
    ans += cur == k;
  }

  cout << ans << '\n';
}
