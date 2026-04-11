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
  int x, n;
  cin >> x >> n;
  vector<int> w(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  vector<int> cur(n + 1, 0);
  int q;
  cin >> q;
  while (q--) {
    int p;
    cin >> p;
    if (cur[p] == 0) {
      x += w[p];
    } else {
      x -= w[p];
    }
    cur[p] ^= 1;
    cout << x << '\n';
  }
}
