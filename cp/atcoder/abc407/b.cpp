/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <iomanip>
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
  int x, y;
  cin >> x >> y;
  int ans = 0;
  for (int a = 1; a <= 6; a++) {
    for (int b = 1; b <= 6; b++) {
      if (a + b >= x || abs(a - b) >= y) {
        ans += 1;
      }
    }
  }
  cout << fixed << setprecision(9) << ((long double)(ans) / (long double)(36));
}
