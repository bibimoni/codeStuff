
/**
 * Author: distiled
 */
#include<bits/stdc++.h>
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
    char c;
    string s;
    cin >> n >> c >> s;
    int ans = 0;
    for (int i = 0; i * 2 < n; i++) {
      if (s[i] != s[n - i - 1]) {
        ans += int(s[i] != c) + int(s[n - i - 1] != c);
      }
    }
    cout << ans << '\n';
  } 
}
