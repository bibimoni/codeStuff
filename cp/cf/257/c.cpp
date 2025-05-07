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

const long double PI = 3.14159265359;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<long double> deg(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    deg[i] = atan(abs(y) / (long double) abs(x));
    deg[i] *= 180.0 / PI;
    if (y >= 0 && x < 0) {
      deg[i] = 2 * 90.0 - deg[i];
    } else if (y < 0 && x < 0) {
      deg[i] += 180.0;
    } else if (y < 0 && x >= 0) {
      deg[i] = 360.0 - deg[i];
    }
  }
  sort(deg.begin(), deg.end());
  auto convert = [&] (long double d) -> long double {
    if (d < 0) {
      return 360.0 + d;
    } 
    return d;
  };
  long double ans = 360;
  if (n == 2) {
    ans = min(convert(deg[1] - deg[0]), convert(deg[0] - deg[1]));
  } else {
    for (int i = 1; i < n; i++) {
      ans = min(ans, convert(360.0 - (deg[i] - deg[i - 1])));
    }
    ans = min(ans, convert(deg[n - 1] - deg[0]));
  }
  cout << fixed << setprecision(9) << ans;
}

