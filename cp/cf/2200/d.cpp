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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    int mn1 = n + 1, id1 = x + 1;
    for (int i = x + 1; i <= y; i++) {
      if (mn1 > a[i]) {
        mn1 = a[i];
        id1 = i;
      }
    }

    vector<int> b;
    for (int i = id1; i <= y; i++) {
      b.push_back(a[i]);
    }
    for (int i = x + 1; i < id1; i++) {
      b.push_back(a[i]);
    }

    vector<int> c;
    for (int i = 1; i <= n; i++) {
      if (x + 1 <= i && i <= y) {
        continue;
      }
      c.push_back(a[i]);
    }
    vector<int> e;
    int j = 0;
    for (j = 0; j < int(c.size()); j++) {
      if (c[j] < b[0]) {
        e.push_back(c[j]);
        continue;
      }
      break;
    }
    for (int v : b) {
      e.push_back(v);
    }
    for (; j < int(c.size()); j++) {
      e.push_back(c[j]);
    }

    for (int i = 0; i < n; i++) {
      cout << e[i] << " \n"[i == n - 1];
    }
  }
}
