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
    const int M = 2;
    vector<vector<int>> a(M, vector<int>(n + 1));
    for (int i = 0; i < M; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }

    vector<int> pmx(n + 1), pmn(n + 1, 2 * n), smx(n + 2), smn(n + 2, 2 * n);
    for (int i = 1; i <= n; i++) {
      pmx[i] = max(pmx[i - 1], a[0][i]);
      pmn[i] = min(pmn[i - 1], a[0][i]);
    }

    for (int i = n; i >= 1; i--) {
      smx[i] = max(smx[i + 1], a[1][i]);
      smn[i] = min(smn[i + 1], a[1][i]);
    }

    vector<int> mx(2 * n + 1);
    for (int j = 1; j <= n; j++) {
      int l = min(pmn[j], smn[j]);
      int r = max(pmx[j], smx[j]);
      mx[r] = max(l, mx[r]);
    }

    vector<int> l(2 * n + 1);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
      l[i] = max(l[i - 1], mx[i]);
      ans += min(i, l[i]);
    }

    cout << ans << '\n';
  }
}
