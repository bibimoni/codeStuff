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
  vector<int> a(m), b(m);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    a[x] += 1;
    b[y] += 1;
  }

  for (int i = 0; i < m; i++) {
    cout << b[i] - a[i] << '\n';
  }
}
