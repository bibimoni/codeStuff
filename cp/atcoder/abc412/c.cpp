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
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    sort(s.begin() + 1, s.end() - 1);
    int ans = 1;
    bool ok = false;
    int ptr = 0;
    while (ptr < n) {
      int nxt = ptr;
      if (s[ptr] * 2 >= s[n - 1]) {
        ok = true;
        ans += 1;
        break;
      }
      while (nxt + 1 < n && s[nxt + 1] <= 2 * s[ptr]) {
        nxt += 1;
      }
      if (ptr == nxt) {
        dbg(nxt, ptr);
        if (nxt == n - 1) {
          ok = true;
        }
        break;
      }
      ans += 1;
      ptr = nxt;
    }
    cout << (ok ? ans : -1) << '\n';
  }
}
