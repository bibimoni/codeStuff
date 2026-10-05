/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#define table(...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (char c : s) {
    cnt[c - 'A'] += 1;
  }

  int n = int(s.size());
  string ans = string(n, '.');
  bool ok = true;
  for (int i = 0; i < n; i++) {
    dbg(ans);
    for (int c = 0; c < 26; c++) {
      if (cnt[c] == 0 || (i > 0 && ans[i - 1] == char(c + 'A'))) {
        continue;
      }
      dbg(char(c + 'A'));
      bool check = true;
      for (int d = 0; d < 26; d++) {
        if (cnt[d] == 0) {
          continue;
        }
        int len = n - i - 1;
        if (d == c) {
          continue;
        }
        if (len < cnt[d] * 2 - 1) {
          dbg(char(d + 'A'), cnt[d], len);
          check = false;
          break;
        }
      }
      if (check) {
        ans[i] = char(c + 'A');
        cnt[c] -= 1;
        break;
      }
    }
    ok &= ans[i] != '.';
  }

  if (!ok) {
    cout << "-1\n";
  } else {
    cout << ans << '\n';
  }
}
