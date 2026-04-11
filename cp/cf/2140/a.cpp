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
    string s;
    cin >> s;
    int cnt1 = count(s.begin(), s.end(), '1');
    int ans = 0;
    for (int i = n - 1; i >= 0 && cnt1 > 0; i--, cnt1--) {
      ans += s[i] != '1';
    }
    cout << ans << '\n';
  }
}
