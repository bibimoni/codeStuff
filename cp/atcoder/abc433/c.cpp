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
  vector<pair<char, int>> a;
  int cnt = 0;
  char prev = '#';
  for (int i = 0; i < int(s.size()); i++) {
    if (s[i] != prev && prev != '#') {
      a.push_back({prev, cnt});
      cnt = 0;
    }
    cnt += 1;
    prev = s[i];
  }
  a.push_back({prev, cnt});

  int ans = 0;
  for (int i = 1; i < int(a.size()); i++) {
    auto [ch1, c1] = a[i - 1];
    auto [ch2, c2] = a[i];
    if (ch2 - ch1 == 1) {
      ans += min(c1, c2);
    }
  }

  cout << ans << '\n';
}
