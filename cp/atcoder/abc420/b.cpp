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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> pts(n);
  for (int j = 0; j < m; j++) {
    int x = 0;

    set<int> tmp;
    for (int i = 0; i < n; i++) {
      x += a[i][j] == '0';
      if (a[i][j] == '0') {
        tmp.insert(i);
      }
    }
    int y = n - x;
    if (x < y) {
      for (int id : tmp) {
        pts[id] += 1;
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (tmp.find(i) == tmp.end()) {
          pts[i] += 1;
        }
      }
    }
  }

  int mx = *max_element(pts.begin(), pts.end());
  for (int i = 0; i < n; i++) {
    if (pts[i] == mx) {
      cout << i + 1 << ' ';
    }
  }
}
