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
  int last = -1;
  for (int i = 0, j = 0; i < int(s.size()); i++) {
    if (s[i] == '#') {
      j += 1;
      if (j == 2) {
        cout << last + 1 << ',' << i + 1 << '\n';
        j = 0;
      } else {
        last = i;
      }
    }
  }
}
