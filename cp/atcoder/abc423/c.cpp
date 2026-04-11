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
  int n, r;
  cin >> n >> r;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int st = 0;
  while (st + 1 <= r && a[st + 1] == 1) {
    dbg(st);
    st += 1;
  }

  int ed = n + 1;
  while (ed - 1 > r && a[ed - 1] == 1) {
    ed -= 1;
  }
  int ans = 0;
  for (int i = st + 1; i < ed; i++) {
    ans += a[i] == 0 ? 1 : 2;
  }

  cout << ans << '\n';
}
