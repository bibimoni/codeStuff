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
    int n, k;
    cin >> n >> k;
    vector cnt(26, 0);
    vector mx(26, 0);
    for (int i = 0; i < n; i++) {
      string t;
      cin >> t;
      vector cnt2(26, 0);
      for (char c : t) {
        cnt[c - 'a'] += 1;
        cnt2[c - 'a'] += 1;
        mx[c - 'a'] = max(mx[c - 'a'], cnt2[c - 'a']);
      }
    }
    int ans = 0;
    for (int c = 0; c < 26; c++) {
      ans += max((cnt[c] + k - 1) / k, mx[c]);
    }
    cout << ans << '\n';
  }
}
