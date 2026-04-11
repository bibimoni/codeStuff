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
  int n;
  cin >> n;

  auto calc = [&](int x1, int y1, int x2, int y2) -> int {
    int d1 = abs(x1 - x2);
    int d2 = abs(y1 - y2);
    return max(d1, d2);
  };

  int rxmx = 0, rymx = 0, rxmn = 1e9, rymn = 1e9;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    a[i] = {r, c};
    rxmx = max(rxmx, r);
    rxmn = min(rxmn, r);
    rymx = max(rymx, c);
    rymn = min(rymn, c);
  }

  int rx = (rxmx + rxmn) / 2;
  int ry = (rymx + rymn) / 2;

  int ans = 1e18;
  for (int dx = max(int(0), rx - 10); dx <= min(int(1e9), rx + 10); dx++) {
    for (int dy = max(int(0), ry - 10); dy <= min(int(1e9), ry + 10); dy++) {
      int cur = 0;
      for (auto [x, y] : a) {
        cur = max(cur, calc(x, y, dx, dy));
      }
      ans = min(ans, cur);
    }
  }

  cout << ans << '\n';
}
