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
  vector<vector<int>> c(n, vector<int>(n));
  for (int i = 0; i + 1 < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> c[i][j];
    }
  }

  int ans = 0;
  for (int a = 0; a < n; a++) {
    for (int b = a + 1; b < n; b++) {
      for (int d = b + 1; d < n; d++) {
        ans += int(c[a][b] + c[b][d] < c[a][d]);
      }
    }
  }

  cout << (ans > 0 ? "Yes\n" : "No\n");
}
