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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += min(a[i], b[i]);
  }

  while (q--) {
    char c;
    int x, v;
    cin >> c >> x >> v;
    cur -= min(a[x], b[x]);
    if (c == 'A') {
      a[x] = v;
    } else {
      b[x] = v;
    }
    cur += min(a[x], b[x]);
    cout << cur << '\n';
  }
}
