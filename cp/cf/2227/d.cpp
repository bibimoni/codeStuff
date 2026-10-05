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
    vector<int> a(2 * n);
    for (int i = 0; i < n * 2; i++) {
      cin >> a[i];
    }

    vector<int> id(n, -1);
    vector<int> dp(2 * n, 1);
    for (int i = 0; i < 2 * n; i++) {
      if (id[a[i]] == -1) {
        id[a[i]] = i;
        continue;
      }
      assert(i > 0);
      int exp = i - dp[i - 1] - 1;
      if (exp == id[a[i]]) {
        dp[i] = dp[i - 1] + 2;
      } else if (a[i] == a[i - 1]) {
        dp[i] = 2;
      }
    }

    int ans = 0;
    for (int i = 2 * n - 1; i >= 0;) {
      vector<int> cur;
      for (int j = i; j >= i - dp[i] + 1; j--) {
        cur.push_back(a[j]);
      }

      sort(cur.begin(), cur.end());
      cur.erase(unique(cur.begin(), cur.end()), cur.end());
      int exp = 0;
      for (int v : cur) {
        if (v != exp) {
          break;
        }
        exp += 1;
      }
      ans = max(ans, exp);

      i = i - dp[i];
    }

    cout << ans << '\n';
  }
}
