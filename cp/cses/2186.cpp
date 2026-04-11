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
  string s;
  cin >> s;
  int n = s.size(), m = 0;
  vector<int> ch(26, -1);
  for (int i = 0; i < n; i++) {
    if (ch[s[i] - 'a'] == -1) {
      ch[s[i] - 'a'] = m;
      m += 1;
    }
  }

  int ans = 0;
  map<array<int, 26>, int> mp;
  array<int, 26> cur;
  cur.fill(0);
  mp[cur] += 1;
  for (int i = 0; i < n; i++) {
    int c = ch[s[i] - 'a'];
    cur[c] += 1;
    bool can = true;
    for (int j = 0; j < m; j++) {
      can &= cur[j] > 0;
    }
    if (can) {
      for (int j = 0; j < m; j++) {
        cur[j] -= 1;
      }
    }
    ans += mp[cur];
    mp[cur] += 1;
  }
  cout << ans << '\n';
}
