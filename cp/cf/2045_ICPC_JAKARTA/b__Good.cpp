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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, d, s;
  cin >> n >> d >> s;
  int ans = s;
  auto dfs = [&] (auto &&self, int cur) -> void {
    if (cur <= n) {
      ans = max(ans, cur);
    } else {
      return;
    }
    for (int mul = 2; cur * (mul - 1) <= d && cur * mul <= n; mul += 1) {
      self(self, cur * mul);
    }
  };
  dfs(dfs, s);
  cout << ans << '\n';
}

