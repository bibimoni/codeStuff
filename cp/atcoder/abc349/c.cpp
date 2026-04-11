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
  int n;
  cin >> n;
  map<int, int> mp;
  for (int y = 1; y * y <= n; y++) {
    for (int x = 1; x < y; x++) {
      if (x * x + y * y > n) {
        continue;
      }
      mp[x * x + y * y] += 1;
    }
  }

  vector<int> ans;
  for (auto [k, v] : mp) {
    if (v == 1) {
      ans.push_back(k);
    }
  }

  cout << ans.size() << '\n';
  for (int i : ans) {
    cout << i << ' ';
  }
}
