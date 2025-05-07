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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    auto go = [&](int x, int y) -> int {
      int ret = -1, val = 0;
      vector<pair<int, int>> dir = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
      for (auto [i, j] : dir) {
        if (i < 0 || j < 0 || i >= n || j >= m)
          continue;
        if (a[x][y] <= a[i][j]) {
          return -1;
        } else {
          val = max(val, a[i][j]);
        }
      }
      return val;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (go(i, j) == -1)
          continue;
        else 
          a[i][j] = go(i, j); 
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << " \n"[j == m - 1];
      }
    }
  }
}


