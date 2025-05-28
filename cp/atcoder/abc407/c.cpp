/**
 * Author: distiled
 */
#include <algorithm>
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
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int n = s.size();
  int ans = 0;
  int diff = 0;
  for (int i = 0; i < n; i++) {
    ans += s[i] - '0' + 1;
    diff += (s[i] - '0') % 10;
    if (i + 1 < n) {
      s[i + 1] = (int(s[i + 1] - '0') - diff + 10 * int(1e9)) % 10 + '0';
    }
  }
  cout << ans << '\n';
}
