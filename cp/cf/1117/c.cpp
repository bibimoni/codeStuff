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
  int xs, ys;
  cin >> xs >> ys;
  int xe, ye;
  cin >> xe >> ye;
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  auto dist = [&] (int x, int y) -> int {
    return abs(x - xe) + abs(y - ye);
  };
  vector<int> x(n + 1, 0), y(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    x[i] = x[i - 1];
    y[i] = y[i - 1];
    if (s[i] == 'U') {
      y[i] += 1;
    } else if (s[i] == 'L') {
      x[i] -= 1;
    } else if (s[i] == 'D') {
      y[i] -= 1;
    } else if (s[i] == 'R') {
      x[i] += 1;
    }
  } 
  int ans = int(1e18);
  for (int i = 1; i <= n; i++) {
    int l = 0, r = int(1e9), ret = int(1e9);
    while (l <= r) {
      int m = (l + r) >> 1;
      int can = m * n + i;
      int nx = x[n] * m + xs + x[i], ny = y[n] * m + ys + y[i];
      if (dist(nx, ny) > can) {
        l = m + 1;
      } else {
        ret = m;
        ans = min(ans, i + n * ret);
        r = m - 1;
      }
    }
    if (ret == int(1e9)) {
      continue;
    }
    ans = min(ans, i + n * ret);
  }
  cout << (ans == int(1e18) ? -1 : ans) << '\n';
}

