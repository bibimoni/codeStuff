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
    vector<int> a(n + 1);
    vector<int> pre(n + 1, 1e9);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = min(pre[i - 1], a[i]);
    }

    vector<int> suf(n + 2);
    for (int i = n; i >= 1; i--) {
      suf[i] = max(suf[i + 1], a[i]);
    }

    string ans = "";
    for (int i = 1; i <= n; i++) {
      if (pre[n] == a[i] || suf[1] == a[i]) {
        ans += '1';
      } else if (min(pre[i - 1], suf[i]) == a[i] ||
                 max(pre[i - 1], suf[i]) == a[i]) {
        ans += '1';
      } else if (max(suf[i + 1], pre[i]) == a[i] ||
                 min(suf[i + 1], pre[i]) == a[i]) {
        ans += '1';
      } else {
        ans += '0';
      }
    }

    cout << ans << '\n';
  }
}
