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
  if ((m == 1 && d == 7) || (m == 3 && d == 3) || (m == 5 && d == 5) ||
      (m == 7 && d == 7) || (m == 9 && d == 9)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
