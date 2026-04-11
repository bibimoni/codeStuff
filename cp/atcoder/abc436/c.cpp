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
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> st;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int r, c;
    cin >> r >> c;
    vector<pair<int, int>> vec{{r, c}, {r + 1, c}, {r, c + 1}, {r + 1, c + 1}};
    bool ok = true;
    for (auto p : vec) {
      ok &= st.find(p) == st.end();
    }
    if (ok) {
      for (auto p : vec) {
        st.insert(p);
      }
      ans += 1;
    }
  }

  cout << ans << '\n';
}
