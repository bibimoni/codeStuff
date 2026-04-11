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
    int n;
    string s;
    cin >> n >> s;

    s = "0" + s;

    bool ok = false;
    vector<int> memo(1 << n, -1);
    auto dfs = [&](auto &&self, int mask) -> bool {
      if (s[mask] == '1') {
        return false;
      }
      if (mask == (1 << n) - 1) {
        return true;
      }
      if (memo[mask] != -1) {
        return memo[mask];
      }
      bool ret = false;
      for (int u = 0; u < n; u++) {
        if ((mask >> u) & 1) {
          continue;
        }
        ret |= self(self, mask | (1 << u));
      }
      memo[mask] = (int)ret;
      return memo[mask];
    };

    for (int u = 0; u < n; u++) {
      ok |= dfs(dfs, (1 << u));
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}
