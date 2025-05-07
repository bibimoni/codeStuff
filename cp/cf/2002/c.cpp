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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
      cin >> points[i].first >> points[i].second;
    }
    int xs, ys, xe, ye;
    cin >> xs >> ys >> xe >> ye;
    auto dist = [&] (int x, int y) -> int {
      return (x - xe) * (x - xe) + (y - ye) * (y - ye);
    };
    bool ok = true;
    int cur = dist(xs, ys);
    for (auto [x, y] : points) {
      ok &= cur < dist(x, y);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


