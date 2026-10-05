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
  string s;
  cin >> s;
  int n = (int)s.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int len = 0; len <= min(i, n - i - 1); len++) {
      cnt += int(s[i - len] != s[i + len]);
      if (cnt > 1) {
        break;
      }
      ans += 1;
    }
    cnt = 0;
    for (int len = 0; len <= min(i, n - i - 2); len++) {
      cnt += int(s[i - len] != s[i + 1 + len]);
      if (cnt > 1) {
        break;
      }
      ans += 1;
    }
  }
  
  cout << ans << '\n';
}
