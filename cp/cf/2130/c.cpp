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
    cin >> n;
    vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      e.push_back({u, v});
    }

    vector<int> was(2 * n + 1);
    vector<int> ans;
    int cur = 0;
    for (auto [u, v] : e) {
      cur += 1;
      bool ok = true;
      for (int i = u; i < v; i++) {
        ok &= was[i] == 0;
      }

      if (ok) {
        ans.push_back(cur);
        for (int i = u; i < v; i++) {
          was[i] = 1;
        }
      }
    }

    cout << ans.size() << '\n';
    for (int x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
