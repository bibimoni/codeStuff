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
  string s, t;
  cin >> s >> t;

  s = " " + s;
  t = " " + t;
  vector<int> pre(n + 2);
  while (m--) {
    int l, r;
    cin >> l >> r;
    pre[l] += 1;
    pre[r + 1] -= 1;
  }

  for (int i = 1; i <= n; i++) {
    pre[i] += pre[i - 1];
  }

  string ans = "";
  for (int i = 1; i <= n; i++) {
    if (pre[i] % 2 == 0) {
      ans += s[i];
    } else {
      ans += t[i];
    }
  }

  cout << ans << '\n';
}
