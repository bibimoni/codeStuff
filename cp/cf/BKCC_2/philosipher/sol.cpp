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
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    vector<int> mark(n + 1);
    for (int i = 0; i < t; i++) {
      int x;
      cin >> x;
      mark[x] = 1;
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
      int l = a[i];
      int r = a[i] + 1 > n ? 1 : a[i] + 1;
      ok &= mark[l] == 1 && mark[r] == 1;
      mark[l] = 0;
      mark[r] = 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
