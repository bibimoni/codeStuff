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
  string s;
  cin >> s;
  string t = "";
  for (int i = 0; i < s.size(); i++) {
    t += s[i];
    if (i == s.size() - 1) {
      break;
    }
    t += 'o';
  }
  cout << t;
}
