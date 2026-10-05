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
  int x = 10000, y = 10000;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    x -= (s == "take" ? a : b);
    y -= a;
  }

  cout << y - x;
}
