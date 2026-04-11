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
  string s, t;
  cin >> s >> t;
  int ans = 1;
  for (int i = 1; i < int(s.size()); i++) {
    if ('A' <= s[i] && s[i] <= 'Z')
      ans &= t.find(s[i - 1]) != string::npos;
  }
  cout << (ans ? "Yes\n" : "No\n") << '\n';
}
