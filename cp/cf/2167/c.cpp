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
    vector<int> a(n);
    int o = 0, e = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      o |= a[i] % 2 == 1;
      e |= a[i] % 2 == 0;
    }

    if (o && e) {
      sort(a.begin(), a.end());
    }
    for (int x : a) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
