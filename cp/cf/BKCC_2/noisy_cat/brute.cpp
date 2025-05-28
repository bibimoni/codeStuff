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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }

    auto ret = a;
    for (int i = k / 2 + 1; i + k / 2 <= n; i++) {
      for (int j = k / 2 + 1; j + k / 2 <= m; j++) {
        vector<int> ll;
        for (int x = i - k / 2; x <= i + k / 2; x++) {
          for (int y = j - k / 2; y <= j + k / 2; y++) {
            ll.push_back(a[x][y]);
          }
        }
        sort(ll.begin(), ll.end());
        ret[i][j] = ll[k * k / 2];
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << ret[i][j] << " \n"[j == m];
      }
    }
  }
}
