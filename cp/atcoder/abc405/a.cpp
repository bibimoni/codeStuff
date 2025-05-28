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

  int r, x;
  cin >> r >> x;
  if (x == 1) {
    if (1600 <= r && r <= 2999) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  } else {
    if (1200 <= r && r <= 2399) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
