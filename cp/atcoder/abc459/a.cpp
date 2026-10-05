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
  int x;
  cin >> x;
  x -= 1;
  string s = "HelloWorld";
  for (int i = 0; i < int(s.size()); i++) {
    if (i == x) {
      continue;
    }
    cout << s[i];
  }
}
