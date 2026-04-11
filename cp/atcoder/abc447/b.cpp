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
  vector<int> cnt(26);
  int mx = 0;
  for (char c : s) {
    cnt[c - 'a']++;
    mx = max(mx, cnt[c - 'a']);
  }

  string t = "";
  for (char c : s) {
    if (cnt[c - 'a'] == mx) {
      continue;
    }
    t += c;
  }
  cout << t;
}
