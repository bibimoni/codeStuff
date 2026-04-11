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
    string s;
    cin >> s;
    bool found = false;
    vector<int> ans;
    for (int mask = 0; mask < (1 << n); mask++) {
      string x = "";
      vector<int> cur;
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
          cur.push_back(i);
          if (cur.size() > 1 && s[cur.back()] < s[cur[cur.size() - 2]]) {
            ok = false;
            break;
          }
        } else {
          x += s[i];
        }
      }
      for (int i = 0; i < x.size() - i; i++) {
        ok &= x[i] == x[x.size() - i - 1];
      }
      if (ok) {
        found = true;
        ans = cur;
        break;
      }
    }

    if (found) {
      cout << ans.size() << '\n';
      for (int x : ans) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
    } else {
      cout << "-1\n";
    }
  }
}
