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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    b[i] -= 1;
  }
  int m;
  cin >> m;
  vector<string> s(m);
  vector cnt(10, vector<vector<int>>(11, vector<int>(26, 0)));
  for (int i = 0; i < m; i++) {
    cin >> s[i];
    for (int j = 0; j < int(s[i].size()); j++) {
      cnt[j][s[i].size()][s[i][j] - 'a'] += 1;
    }
  }

  for (int i = 0; i < m; i++) {
    bool ok = true;
    string &t = s[i];
    if ((int)s[i].size() != n) {
      cout << "No\n";
      continue;
    }
    for (int j = 0; j < int(t.size()); j++) {
      ok &= int(cnt[b[j]][a[j]][t[j] - 'a'] > 0);
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}
