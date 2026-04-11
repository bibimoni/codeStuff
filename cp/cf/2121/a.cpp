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
    int n, s;
    cin >> n >> s;
    vector<int> x;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      x.push_back(v);
    }

    if (s < x[0]) {
      cout << x[n - 1] - s;
    } else if (s > x[n - 1]) {
      cout << s - x[0];
    } else {
      cout << min(s - x[0] + x[n - 1] - x[0], x[n - 1] - s + x[n - 1] - x[0]);
    }
    cout << '\n';
  }
}
