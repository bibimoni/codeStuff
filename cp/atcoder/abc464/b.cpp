/**
 * Author: distiled
 */
#include<bits/stdc++.h>
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
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  int lh = h, rh = 0, lw = w, rw = 0;
  for (int i = 0; i < h; i++) {
    cin>> a[i];
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        lh = min(lh, i);
        rh = max(rh, i);
        lw = min(lw, j);
        rw = max(rw, j);
      }
    }
  }
  for (int i = lh; i <= rh; i++) {
    for (int j = lw; j <= rw; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }


}
