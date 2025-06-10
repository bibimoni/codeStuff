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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    ok |= s[i] == 'o' && t[i] == 'o';
  }
  cout << (ok ? "Yes" : "No");
}
