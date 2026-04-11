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
  int q, w;
  cin >> q >> w;
  vector<int> a(w + 1);
  set<pair<int, int>> peek;
  for (int j = 0; j < q; j++) {
    int x, y;
    cin >> x >> y;
    bool has = peek.find({x, y}) != peek.end();
    for (int i = max(0, x - y); i <= min(w, x + y); i++) {
      a[i] += (has ? -1 : 1);
    }
    if (has) {
      peek.erase({x, y});
    } else {
      peek.insert({x, y});
    }

    cout << accumulate(a.begin(), a.end(), 0) << '\n';
  }
}
