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
  int a, b, c;
  cin >> a >> b >> c;
  int x1 = max({a, b, c});
  int x3 = min({a, b, c});
  int x2 = a + b + c - x1 - x3;
  cout << x1 * 100 + x2 * 10 + x3;
}
