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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    queue<pair<int, int>> stock;
    for (int i = 0; i < n; i++) {
      stock.push({i, a[i]});
      int cur = b[i];
      dbg(i);
      while (cur) {
        auto &[_, v] = stock.front();
        if (cur >= v) {
          cur -= v;
          stock.pop();
        } else {
          v -= cur;
          cur = 0;
        }
      }
      if (stock.size()) {
        while (i - stock.front().first >= d) {
          stock.pop();
        }
      }
    }

    int ans = 0;
    while (stock.size()) {
      ans += stock.front().second;
      stock.pop();
    }
    cout << ans << '\n';
  }
}
