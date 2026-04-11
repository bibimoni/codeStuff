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
  int n = s.size(), m = t.size();
  s = " " + s;

  vector<vector<int>> nxt(n + 2, vector<int>(26, n + 1));
  for (char c = 'a'; c <= 'z'; c++) {
    int j = c - 'a';
    for (int i = n; i >= 1; i--) {
      if (s[i] == c) {
        nxt[i][j] = i;
      } else {
        nxt[i][j] = nxt[i + 1][j];
      }
    }
  }

  int64_t ans = 0;
  for (int i = 1; i <= n; i++) {
    int cur = i - 1, j = 0;
    while (cur <= n && j < m) {
      cur += 1;
      int c = t[j] - 'a';
      cur = nxt[cur][c];
      j += 1;
    }

    ans += cur - i;
  }
  cout << ans << '\n';
}
