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
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }

    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
      }
    }

    bool ok = true;
    vector<int> was(n);
    for (int i = 0; i < n; i++) {
      bool tmp = false;
      for (int j = 0; j < n; j++) {
        if (was[j]) {
          continue;
        }

        auto t = a[i];
        for (int k = 1; k <= m; k++) {
          rotate(t.begin(), t.begin() + 1, t.end());
          dbg(t, b[j]);
          if (t == b[j]) {
            was[j] = 1;
            tmp = true;
            break;
          }
        }
        if (tmp) {
          break;
        }
      }
      ok &= tmp;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
