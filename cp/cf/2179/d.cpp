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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    vector<int> cur;
    auto dfs = [&](auto &&self, int j) -> void {
      if (j == 1) {
        cur = {1, 0};
        return;
      }

      self(self, j - 1);

      for (int &x : cur) {
        x = 2 * x + 1;
      }

      for (int i = 0; i < (1 << (j - 1)); i++) {
        cur.push_back(2 * i);
      }
    };
    dfs(dfs, n);

    for (int i = 0; i < (1 << n); i++) {
      cout << cur[i] << " \n"[i == (1 << n) - 1];
    }
  }
}
