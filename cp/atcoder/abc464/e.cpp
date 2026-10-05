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
  int h, w, q;
  cin >> h >> w >> q;
  vector<int> r(q), c(q);
  vector<char> t(q);
  for (int i = 0; i < q; i++) {
    cin >> r[i] >> c[i] >> t[i];
    r[i] -= 1;
    c[i] -= 1;
  }

  vector<vector<char>> a(h, vector<char>(w, '.'));
  int cnt = 0;
  for (int id = q - 1; id >= 0; id--) {
    int x = r[id], y = c[id];
    char ch = t[id];
    int by = 0;
    for (int i = x; i >= 0; i--) {
      for (int j = y; j >= by; j--) {
        if (a[i][j] != '.') {
          by = j + 1;
          break;
        }
        a[i][j] = ch;
        cnt += 1;
      }
      if (by > y) {
        break;
      }
    }
    
    if (cnt == h * w) {
      break;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << (a[i][j] == '.' ? 'A' : a[i][j]);
    }
    cout << '\n';
  }
}
