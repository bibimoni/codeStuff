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
  int cnt = 100;
  while (cnt--) {
    int cur = 0;
    while (n) {
      cur += (n % 10) * (n % 10);
      n /= 10;
    }
    n = cur;
    if (n == 1) {
      break;
    }
  }

  cout << (n == 1 ? "Yes\n" : "No\n");
}
