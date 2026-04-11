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
  string s, t;
  cin >> s >> t;
  int ans = m * 10;
  for (int i = 0; i + m - 1 < n; i++) {
    int cur = 0;
    int j = i;
    for (char v : t) {
      if (v <= s[j]) {
        cur += s[j] - v;
      } else {
        cur += ('9' - v) + s[j] - '0' + 1;
      }
      j += 1;
    }

    ans = min(ans, cur);
  }
  cout << ans << '\n';
}
