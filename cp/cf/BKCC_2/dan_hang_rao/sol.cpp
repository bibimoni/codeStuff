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
    int n, r, c;
    cin >> n >> r >> c;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
      cin >> h[i];
    vector<int> w(n);
    for (int i = 0; i < n; i++)
      cin >> w[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += ((w[i] + r - 1) / r) * ((h[i] + c - 1) / c);
    }
    cout << ans << '\n';
  }
}
