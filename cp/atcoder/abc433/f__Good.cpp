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
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    string t = "";
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        t += s[i];
      }
    }

    bool ok = t.size() % 2 == 0;
    string t1 = t.substr(0, t.size() / 2);
    string t2 = t.substr(t.size() / 2, t.size() / 2);
    char p = t1[0];
    for (char i : t1) {
      ok &= i == p;
    }
    p = t2[0];
    for (char i : t2) {
      ok &= i == p;
    }
    if (t1[0] + 1 == t2[0]) {
      ans += int(ok);
    }
  }
  cout << ans << '\n';
}
