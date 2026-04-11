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
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i] -= 1;
  }

  const int LG = 30;
  vector jump(n, vector<int>(LG));
  for (int i = 0; i < n; i++) {
    jump[i][0] = p[i];
  }
  for (int j = 1; j < LG; j++) {
    for (int i = 0; i < n; i++) {
      jump[i][j] = jump[jump[i][j - 1]][j - 1];
    }
  }

  while (q--) {
    int x, k;
    cin >> x >> k;
    x -= 1;
    for (int j = 0; j < LG; j++) {
      if ((k >> j) & 1) {
        x = jump[x][j];
      }
    }
    cout << x + 1 << '\n';
  }
}
