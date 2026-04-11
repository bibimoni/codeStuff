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
    int n;
    cin >> n;
    string t = to_string(n);
    int ans = -1;
    for (int v = 0; v <= 10000; v++) {
      if (ans != -1) {
        break;
      }
      string vv = to_string(v);
      for (char c : t) {
        if (vv.find(c) != string::npos) {
          ans = v;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}
