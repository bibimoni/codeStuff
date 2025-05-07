// time-limit: 3000
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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int g, h, i, j, k, l;
  cin >> g >> h >> i >> j >> k >> l;
  bool ok = false;
  {
    auto inside = [&] (int m, int n, int o) -> bool {
      return g < m && m < j && h < n && n < k && i < o && o < l;
    };
    for (int x = a; x <= d; x++) {
      for (int y = b; y <= e; y++) {
        for (int z = c; z <= f; z++) {
          ok |= inside(x, y, z);
        }
      }
    }
  }
  {
    auto inside = [&] (int m, int n, int o) -> bool {
      return a < m && m < d && b < n && n < e && c < o && o < f;
    };
    for (int x = g; x <= j; x++) {
      for (int y = h; y <= k; y++) {
        for (int z = i; z <= l; z++) {
          ok |= inside(x, y, z);
        }
      }
    }
  }
  cout << (ok ? "Yes\n" : "No\n");
}


