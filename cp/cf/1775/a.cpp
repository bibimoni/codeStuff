/**
 * Author: distiled
 */
#include<bits/stdc++.h>
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
    int n = s.size();
    int idx = -1;
    for (int i = 1; i < n - 1; i++) {
      if (s[i] <= s[0] && s[i] <= s[i + 1]) {
        idx = i;
        break;
      }
    }
    if (idx != -1) {
      cout << s.substr(0, idx) << ' ' << s[idx] << ' ' << s.substr(idx + 1) << '\n';
      continue;
    }
    for (int i = 1; i < n - 1; i++) {
      if (s[i] >= s[0] && s[i] >= s[n - 1]) {
        idx = i;
        break;
      }
    }
    if (idx != -1) {
      cout << s.substr(0, idx) << ' ' << s.substr(idx, n - idx - 1) << ' ' << s[n - 1] << '\n';
      continue;
    }
    cout << idx << '\n';
  }
}

