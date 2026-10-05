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
  vector<int> ans(m, -1);
  for (int i = 0; i < n; i++) {
    int c, s;
    cin >> c >> s;
    c -= 1;
    ans[c] = max(ans[c], s);
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}
