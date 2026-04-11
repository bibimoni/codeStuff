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
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  sort(x.begin(), x.end());
  vector<pair<int, int>> g;
  for (int i = 0; i + 1 < n; i++) {
    g.push_back({x[i + 1] - x[i], i});
  }

  sort(g.begin(), g.end(), greater<>());
  vector<int> mark(n);
  for (int i = 0; i < m - 1; i++) {
    auto [_, ii] = g[i];
    mark[ii] = 1;
  }

  int ans = 0, last = x[0];
  for (int i = 0; i < n; i++) {
    if (mark[i]) {
      ans += x[i] - last;
      if (i + 1 < n) {
        last = x[i + 1];
      } else {
        last = -1;
      }
    }
  }

  if (last != -1) {
    ans += x[n - 1] - last;
  }
  cout << ans << '\n';
}
