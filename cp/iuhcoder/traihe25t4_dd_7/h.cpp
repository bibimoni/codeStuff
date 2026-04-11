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
  int n, k;
  cin >> n >> k;

  int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    string s = "";
    for (int j = 0; j < n; j++) {
      if ((mask >> j) & 1) {
        s += '1';
      } else {
        s += '0';
      }
    }
    bool ok = true;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += 1;
      ok &= cnt <= k;
      if (i + 1 < n && s[i] != s[i + 1]) {
        cnt = 0;
      }
    }
    ok &= cnt <= k;
    ans += int(ok);
  }

  cout << ans << '\n';
}
