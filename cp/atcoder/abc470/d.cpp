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
  array<vector<int>, 2> p;
  p[0] = vector<int>(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[0][i];
  }

  p[1] = vector<int>(n + 1);
  for (int i =1 ; i <= n; i++) {
    p[1][p[0][i]] = i;
  }

  int st = 0;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x, y;
      cin >> x >> y;
      swap(p[st ^ 1][p[st][x]], p[st ^ 1][p[st][y]]);
      swap(p[st][x], p[st][y]); 
    } else {
      st ^= 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << p[st][i] << " \n"[i == n];
  }
}
