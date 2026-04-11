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
  int m, a, b;
  cin >> m >> a >> b;

  vector<int> was(m * m);
  vector<int> can(m * m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0)
        can[i * m + j] = 1;
    }
  }
  auto dfs = [&](auto &&self, int u) -> bool {
    if (was[u]) {
      return can[u];
    }
    was[u] = 1;
    int cx = u % m;
    int cy = u / m;
    int cur = a * cy + b * cx;
    can[u] = self(self, cy * m + cur);
    return can[u];
  };

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      dfs(dfs, i * m + j);
    }
  }

  cout << m * m - accumulate(can.begin(), can.end(), 0);
}
