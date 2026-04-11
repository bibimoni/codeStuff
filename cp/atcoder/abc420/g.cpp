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
  int X;
  cin >> X;

  int x41 = 4 * X - 1;
  vector<pair<int, int>> factor;
  for (int i = 1; i * i <= abs(x41); i++) {
    if (abs(x41) % i == 0) {
      int j = x41 / i;
      factor.emplace_back(i, j);
    }
  }

  set<int> ans;
  for (auto [p, q] : factor) {
    if (abs(p) % 2 != abs(q) % 2) {
      continue;
    }

    for (auto sign : {1, -1}) {
      p *= sign;
      q *= sign;
      int d = (q - p) / 2;
      if ((d - 1) % 2 == 0) {
        int n = (d - 1) / 2;
        ans.insert(n);
      }
      if (abs(-d - 1) % 2 == 0) {
        int n = (-d - 1) / 2;
        ans.insert(n);
      }
    }
  }

  cout << ans.size() << '\n';
  for (int v : ans) {
    cout << v << ' ';
  }
}
