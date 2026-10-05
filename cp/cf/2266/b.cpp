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
    int a, b, c;
    cin >> a >> b >> c;
    if (abs(a + c - b) > abs(a - b)) {
      cout << abs(a + c - b) << '\n';
    } else if (abs(a - b) > abs(a - b - c)) {
      cout << abs(a - b- c) << '\n';
    } else {
      cout << abs(a - b) << '\n';
    }
  }
}
