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
  string s, t;
  cin >> s >> t;

  string as = "";
  vector<int> cs;
  int cur = 0;
  for (char c : s) {
    if (c != 'A') {
      as += c;
      cs.push_back(cur);
      cur = 0;
    } else {
      cur += 1;
    }
  }
  cs.push_back(cur);

  string at = "";
  vector<int> ct;
  cur = 0;
  for (char c : t) {
    if (c != 'A') {
      at += c;
      ct.push_back(cur);
      cur = 0;
    } else {
      cur += 1;
    }
  }
  ct.push_back(cur);

  if (at != as) {
    cout << "-1\n";
    return 0;
  }

  assert(ct.size() == cs.size());
  int ans = 0;
  for (int i = 0; i < (int)ct.size(); i++) {
    ans += abs(ct[i] - cs[i]);
  }
  cout << ans << '\n';
}
