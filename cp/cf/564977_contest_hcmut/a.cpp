// time-limit: 3000
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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  string ans = string(1, a[1][1]);
  set<pair<int, int>> cur = {{1, 1}};
  set<pair<int, int>> off = {{1, 0}, {0, 1}};
  for (int step = 2; step < n + m; step ++) {
    set<pair<int, int>> n_cur;
    char mn = 'z';
    for (auto [x, y] : cur) {
      for (auto [dx, dy] : off) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx <= n && ny <= m) {
          mn = min(mn, a[nx][ny]);
        }
      }
    }
    ans += string(1, mn);
    for (auto [x, y] : cur) {
      for (auto [dx, dy] : off) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx <= n && ny <= m) {
          if (a[nx][ny] == mn) {
            n_cur.insert(pair<int, int>{nx, ny});
          }
        }
      }
    }
    cur = n_cur;
  }
  cout << ans << '\n';
}



