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
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int c = s[0] - 'a';
    int x = c / 3 + 2;
    if (x <= 6) {
      cout << x;
    } else if ('p' <= s[0] && s[0] <= 's') {
      cout << 7;
    } else if ('t' <= s[0] && s[0] <= 'v') {
      cout << 8;
    } else {
      cout << 9;
    }
  }
}
