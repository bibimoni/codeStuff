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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int, char>> v;
    int cur = 0;
    char prev = '#';
    for (char x : s) {
      if (x != prev) {
        if (cur) {
          v.emplace_back(cur, prev);
        }
        cur = 1;
        prev = x;
      } else {
        cur += 1;
      }
    }
    v.emplace_back(cur, prev);

    if (v.size() == 1) {
      cout << "0\n";
      continue;
    } else if (v.size() == 2) {
      cout << min(v[0].first, v[1].first) << '\n';
      continue;
    }

    int ed = 0, ed0 = 0;
    n = int(v.size());
    for (int i = n - 1; i - 2 >= 0; i--) {
      ed += v[i].first;
      ed0 += int(v[i].second == '0') * v[i].first;
    }

    int st = 0, st0 = 0, ans = int(1e9);
    int st1, ed1;
    for (int i = 0; i + 2 < n; i++) {
      ed0 -= int(v[i + 2].second == '0') * v[i + 2].first;
      ed -= v[i + 2].first;

      ed1 = ed - ed0;
      st1 = st - st0;
      auto [_, ch] = v[i];
      if (ch == '0') {
        ans = min(ans, ed + st + st1 + v[i].first + v[i + 2].first + ed1);
      } else {
        dbg(ed, st, st0, ed0);
        ans = min(ans, ed + st + st0 + v[i].first + v[i + 2].first + ed0);
      }

      st0 += int(v[i].second == '0') * v[i].first;
      st += v[i].first;
    }

    cout << ans << '\n';
  }
}
