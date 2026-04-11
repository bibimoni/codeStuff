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
  int n, k, x;
  cin >> n >> k >> x;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<string> store;
  auto dfs = [&](auto &&self, int len, string val) -> void {
    if (len == k) {
      store.push_back(val);
      return;
    }
    for (int i = 0; i < n; i++) {
      self(self, len + 1, val + s[i]);
    }
  };

  dfs(dfs, 0, "");
  sort(store.begin(), store.end());
  cout << store[x - 1];
}
