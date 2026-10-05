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
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    int rem = 1000 - (v % 1000);
    x += rem % 10;
    rem /= 10;
    y += rem % 10;
    rem /= 10;
    z += rem % 10;
  }
  cout << x << ' ' << y << ' ' << z;
}
