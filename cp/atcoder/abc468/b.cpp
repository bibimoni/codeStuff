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
  int m, d;
  cin >> m >> d;
  string s;
  cin >> s;
  int last = m * 5;
  int beg = -m * 5;
  for (int i = 0; i < m; i++) {
    if (s[i] == 'G') {
      last = i;
      break;
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (last -i > d && i - beg > d) {
      ans += 1;
    }
    if (s[i] == 'G') {
      last = m * 5;
      for (int j = i + 1; j < m; j++) {
        if (s[j] == 'G') {
          last = j;
          break;
        }
      }
      beg = i;
    }
  }

  cout << ans << '\n';
}
