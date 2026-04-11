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
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int s1 = 0;
    for (int i = 0; i < n; i++) {
      bool c1 = false;
      for (int j = 0; j < n; j++) {
        c1 |= a[i][j] == '#';
      }
      s1 += int(c1);
    }

    int s2 = 0;
    for (int j = 0; j < n; j++) {
      bool c2 = false;
      for (int i = 0; i < n; i++) {
        c2 |= a[i][j] == '#';
      }
      s2 += int(c2);
    }

    cout << min(s1, s2) << '\n';
  }
}
