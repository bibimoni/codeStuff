/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <iomanip>
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
  vector<long double> ans(m);
  vector<int> cnt(m);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    ans[a] += b;
    cnt[a] += 1;
  }

  for (int k = 0; k < m; k++) {
    cout << fixed << setprecision(9) << ans[k] / cnt[k] << '\n';
  }
}
