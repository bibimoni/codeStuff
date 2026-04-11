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
  int x, c;
  cin >> x >> c;
  int ans = 0;
  for (int i = 1000; i <= x; i += 1000) {
    if (i + (i / 1000) * c > x) {
      continue;
    }
    ans = i;
  }

  cout << ans << '\n';
}
