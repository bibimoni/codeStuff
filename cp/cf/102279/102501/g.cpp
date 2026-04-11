/**
 * Author: distiled
 */
#include <algorithm>
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

  int s, l, n;
  cin >> s >> l >> n;

  vector<string> ss(s);
  for (int i = 0; i < s; i++) {
    cin >> ss[i];
  }

  ss.erase(unique(ss.begin(), ss.end()), ss.end());
  auto find = [&](string &s) -> int {
    return lower_bound(ss.begin(), ss.end(), s) - ss.begin();
  };

  for (int i = 0; i < l; i++) {
    string u, v;
    cin >> u >> v;
  }
}
