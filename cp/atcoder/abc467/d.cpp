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
  int tt;
  cin >> tt;
  while (tt--) {
    int px, py, qx, qy, rx, ry, sx, sy;
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
    int ux = px - qx;
    int uy = py - qy;
    int vx = rx - sx;
    int vy = ry - sy;
    int prod = (ux * vy) - (uy * vx);
    if (prod != 0) {
      cout << "Yes\n";
      continue;
    }
    int umx = (px + qx);
    int umy = (py + qy);
    int vmx = (rx + sx);
    int vmy = (ry + sy);
    int vumx = vmx - umx;
    int vumy = vmy - umy;
    prod = ux * (vumx) + uy * (vumy);
    if (prod != 0) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}
