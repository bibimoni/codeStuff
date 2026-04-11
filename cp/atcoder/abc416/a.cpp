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
  int n, l, r;
  cin >> n >> l >> r;
  string s;
  cin >> s;
  bool ok = true;
  for (int i = l - 1; i < r; i++) {
    ok &= s[i] == 'o';
  }
  cout << (ok ? "Yes\n" : "No\n");
}
