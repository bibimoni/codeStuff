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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (is_sorted(s.begin(), s.end())) {
      cout << 0 << '\n';
      continue;
    }

    vector<int> suf(n);
    for (int i = n - 1; i >= 0; i--) {
      suf[i] = (i == n - 1 ? 0 : suf[i + 1]) + int(s[i] == '1');
    }

    int b1 = 0, b0 = s[0] == '0', ans = n - 1;
    for (int i = 0; i < n; i++) {
      b1 |= s[i] == '1';
      if (b1 && b0) {
        int l1 = suf[0] - suf[i]; 
        int r0 = n - 1 - i + 1 - suf[i];
        ans = min(ans, l1 + r0);
      }
    }
    if (b0) { ans = min(ans, suf[0]); }
    if (s[0] == '1') { ans = min(ans, n - suf[0]); }

    cout << ans << '\n';
  }
}
