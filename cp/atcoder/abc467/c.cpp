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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }

  int ans = n;
  for (int st = 0; st < 2; st++) {
    int c = (a[0] % 2 != st);
    int cur = st;
    for (int i = 0; i < n - 1; i++) {
      cur ^= b[i];
      c += (a[i + 1] % 2 != cur);
    }
    ans = min(ans, c);
  }

  cout << ans << '\n';
}
