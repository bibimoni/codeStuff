/**
 * Author: distiled
 */
#include<bits/stdc++.h>
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
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<pair<int, int>> cur{{0, 0}};
  vector<vector<int>> was(n, vector<int>(n));
  was[0][0] = 1;
  string ans = string(1, a[0][0]);
  for (int i = 0; i < 2 * n - 2; i++) {
    vector<pair<char, pair<int, int>>> s;
    for (auto [x, y] : cur) {
      for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {0, 1}}) {
        int nx = x + dx, ny = y + dy;
        if (nx >= n || ny >= n) {
          continue;
        }

        if (was[nx][ny]) {
          continue;
        } 

        s.push_back({a[nx][ny], {nx, ny}});
        was[nx][ny] = 1;
      }
    }

    cur.clear();

    sort(s.begin(), s.end());
    for (int j = 0; j < int(s.size()); j++) {
      if (j > 0 && s[j].first != s[j - 1].first) {
        break;
      }

      cur.push_back(s[j].second); 
    }

    assert(s.size() > 0);
    ans += s[0].first;
  }

  cout << ans;
}
