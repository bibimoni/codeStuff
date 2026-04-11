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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    int mx = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        mx = max(a[i][j], mx);
      }
    }

    vector<int> rows(n), cols(m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == mx) {
          rows[i] += 1;
          cols[j] += 1;
          cnt += 1;
        }
      }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (rows[i] + cols[j] - int(a[i][j] == mx) == cnt) {
          ok = true;
        }
      }
    }

    cout << (mx - int(ok)) << '\n';
  }
}
