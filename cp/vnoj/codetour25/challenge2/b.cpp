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

  int n = s.size();
  vector<vector<int>> prev(n, vector<int>(26, -1));
  for (int ch = 0; ch < 26; ch++) {
    int cur_ch = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] - 'a' == ch) {
        cur_ch = i;
      }
      prev[i][ch] = cur_ch;
    }
  }

  vector<int> cur(26, 0);
  map<vector<int>, int> mp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cur[s[i] - 'a'] += 1;
    set<pair<int, int>, greater<>> consider;
    for (int c = 0; c < 26; c++) {
      if (prev[i][c] == -1) {
        continue;
      }
      consider.insert({prev[i][c], c});
    }
    for (auto [_, ch] : consider) {
      if (cur[ch] > 0) {
        cur[ch] -= 1;
        ans = max(ans, i - mp[cur]);
        mp[cur] += 1;
      }
    }
  }
}
