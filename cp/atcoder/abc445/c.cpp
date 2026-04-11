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
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    c[i] -= 1;
  }
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    if (ans[i] != -1) {
      continue;
    }
    vector<int> cur{i};
    int x = i;
    while (c[x] != x) {
      x = c[x];
      cur.push_back(x);
    }
    for (int v : cur) {
      ans[v] = x;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " \n"[i == n - 1];
  }
}
