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
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }

    vector<int> pmn(n + 1, n + 1), smx(n + 2);
    for (int i = 1; i <= n; i++) {
      pmn[i] = min(pmn[i - 1], p[i]);
    }
    for (int i = n; i >= 1; i--) {
      smx[i] = max(smx[i + 1], p[i]);
    }
    bool ok = true;
    for (int i = 1; i + 1 <= n; i++) {
      ok &= pmn[i] < smx[i + 1];
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}
