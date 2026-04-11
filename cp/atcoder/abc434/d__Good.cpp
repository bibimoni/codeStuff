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
  int n;
  cin >> n;
  vector<array<int, 4>> rec;
  const int N = 2000;
  vector pre(N + 1, vector(N + 1, 0));
  for (int i = 0; i < n; i++) {
    int u, d, l, r;
    cin >> u >> d >> l >> r;
    rec.push_back({u, d, l, r});
    for (int x = u; x <= d; x++) {
      for (int y = l; y <= r; y++) {
        pre[x][y] += 1;
      }
    }
  }

  for (auto p : rec) {
    int x1 = p[0], x2 = p[1], y1 = p[2], y2 = p[3];
    auto pp = pre;
    int ans = 0;
    for (int x = x1; x <= x2; x++) {
      for (int y = y1; y <= y2; y++) {
        pp[x][y] -= 1;
      }
    }
    for (int x = 1; x <= N; x++) {
      for (int y = 1; y <= N; y++) {
        ans += pp[x][y] == 0;
      }
    }
    cout << ans << '\n';
  }
}
