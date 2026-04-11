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
  int H, W, n;
  cin >> H >> W >> n;
  vector<int> h(n), w(n);
  map<int, vector<int>> hs, ws;
  for (int i = 0; i < n; i++) {
    cin >> h[i] >> w[i];
    hs[h[i]].push_back(i);
    ws[w[i]].push_back(i);
  }

  int ch = H, cw = W;
  vector<int> xs(n, -1), ys(n, -1);
  int x = 1, y = 1, cnt = n;
  while (cnt > 0) {
    for (int id : hs[ch]) {
      if (xs[id] != -1) {
        continue;
      }
      xs[id] = x;
      ys[id] = y;
      y += w[id];
      cw -= w[id];
      cnt -= 1;
    }
    for (int id : ws[cw]) {
      if (xs[id] != -1) {
        continue;
      }
      xs[id] = x;
      ys[id] = y;
      x += h[id];
      ch -= h[id];
      cnt -= 1;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << xs[i] << " " << ys[i] << "\n";
  }
}
