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
    int n, k;
    cin >> n >> k;

    vector<vector<int>> ans(n + 1, vector<int>(n + 1));

    vector<pair<int, int>> cands(2 * n - 1);
    for (int i = 0, x = 1; i < 2 * n - 1; i += 2) {
      dbg(i);
      cands[i] = {1, x};
      x += 1;
    }
    for (int i = 2 * n - 3, x = 2; i > 0; i -= 2) {
      dbg(i);
      cands[i] = {x, 1};
      x += 1;
    }

    int id = 0, cx = -1, cy = -1;
    vector<int> r(n + 1), c(n + 1);
    while (k--) {
      if (cx < 1 || cy < 1 || cx > n || cy > n) {
        cx = cands[id].first;
        cy = cands[id].second;
        id += 1;
      }
      ans[cx][cy] = 1;
      r[cx] += 1;
      c[cy] += 1;
      cx += 1;
      cy += 1;
    }

    int rmx = *max_element(r.begin() + 1, r.end());
    int rmn = *min_element(r.begin() + 1, r.end());
    int cmx = *max_element(c.begin() + 1, c.end());
    int cmn = *min_element(c.begin() + 1, c.end());

    cout << (rmx - rmn) * (rmx - rmn) + (cmx - cmn) * (cmx - cmn) << '\n';

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
}
