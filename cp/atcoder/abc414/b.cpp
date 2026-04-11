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
  int n;
  cin >> n;
  string ans = "";
  bool ok = true;
  for (int i = 0; i < n; i++) {
    char c;
    int l;
    cin >> c >> l;
    if (!ok) {
      continue;
    }
    if (ans.size() + l > 100) {
      ans = "Too Long";
      ok = false;
    } else {
      ans += string(l, c);
    }
  }
  cout << ans << '\n';
}
