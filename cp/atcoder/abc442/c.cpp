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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> off(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    off[u] += 1;
    off[v] += 1;
  }

  auto c3 = [&](int x) -> int64_t {
    if (x < 3) {
      return int64_t(0);
    }
    return 1LL * (x - 2) * (x - 1) * x / 6;
  };

  for (int i = 0; i < n; i++) {
    cout << c3(n - off[i] - 1) << " \n"[i == n - 1];
  }
}
