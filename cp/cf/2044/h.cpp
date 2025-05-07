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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<int>> rows(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
      int cur = 1;
      for (int j = 1; j <= n; j++) {
        rows[i][j] = a[i][j] * cur;
        cur += 1;
      }
    }

    vector<vector<int>> cols(n + 1, vector<int>(n + 1));
    for (int j = 1; j <= n; j++) {
      int cur = 1;
      for (int i = 1; i <= n; i++) {
        cols[i][j] = a[i][j] * cur;
        cur += 1;
      }
    }
    
    auto makepp = [&] (vector<vector<int>> &p) -> vector<vector<int>> {
      vector<vector<int>> ret(n + 1, vector<int>(n + 1, 0));
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          ret[i][j] = p[i][j] + ret[i - 1][j] + ret[i][j - 1] - ret[i - 1][j - 1];
        }
      }
      return ret;
    };
    auto app = makepp(a);
    auto rpp = makepp(rows);
    auto cpp = makepp(cols);

    auto querypp = [&] (vector<vector<int>> &p, int x1, int y1, int x2, int y2) -> int {
      return p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1];
    };

    while (q--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int rr = querypp(rpp, x1, y1, x2, y2) - (y1 - 1) * querypp(app, x1, y1, x2, y2);
      int cc = (querypp(cpp, x1, y1, x2, y2) - x1 * querypp(app, x1, y1, x2, y2)) * (y2 - y1 + 1);
      cout << rr + cc << ' ';
    }
    cout << '\n';

  }
}

