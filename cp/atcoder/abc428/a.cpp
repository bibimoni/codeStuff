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
  int s, a, b, x;
  cin >> s >> a >> b >> x;
  int opt = 0, ans = 0;
  for (int i = 0; i <= x;) {
    int t = min(x - i, a);
    ans += (opt ? 0 : s * t);
    i += opt ? b : a;
    opt ^= 1;
  }

  cout << ans << '\n';
}
