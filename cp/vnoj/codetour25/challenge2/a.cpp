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
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    if (s.size() == 1) {
      cout << (s[0] == 'A' ? "YES YES\n" : "NO NO\n");
      continue;
    }
    bool x = true;
    for (int i = 0; i + 1 < int(s.size()); i++) {
      x &= !(s[i] == 'A' && s[i + 1] == 'A');
    }
    bool y = s[0] == 'A';
    for (int i = 0; i + 1 < int(s.size()); i++) {
      y &= !(s[i] == 'A' && s[i + 1] == 'A');
    }

    cout << (x ? "YES" : "NO") << ' ' << (y ? "YES\n" : "NO\n");
  }
}
