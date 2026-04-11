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
  int n;
  cin >> n;
  vector ans(n, vector<int>(n));
  int x = 0, y = n / 2, step = 0;
  while (step < n * n) {
    step += 1;
    ans[x][y] = step;
    if (ans[(x - 1 + n) % n][(y + 1) % n] == 0) {
      x = (x - 1 + n) % n;
      y = (y + 1) % n;
    } else {
      x = (x + 1) % n;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " \n"[j == n - 1];
    }
  }
}
