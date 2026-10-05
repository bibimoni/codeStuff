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
  int n = int(s.size());
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != 'C') {
      continue;
    }
    int l = i;
    int r = n - i - 1;
    int mn = min(l, r) + 1;
    ans += mn;
  }
  cout << ans << '\n';
}
