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
    string s;
    cin >> n >> s;
    string ans = "";
    for (int i = 0; i < n; i++) {
      if (i < n - 1 && s[i] > s[i + 1]) {
        int npos = n - 1;
        for (int j = i + 2; j < n; j++) {
          if (s[j] > s[i]) {
            npos = j - 1;
            break;
          }
        }
        ans += s.substr(i + 1, npos - i);
        ans.push_back(s[i]);
        if (npos + 1 < n) {
          ans += s.substr(npos + 1);
        }
        break;
      } else {
        ans.push_back(s[i]);
      }
    }
    cout << ans << '\n';
  }
}
