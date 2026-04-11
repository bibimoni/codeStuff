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
    int a, b;
    cin >> a >> b;
    vector<int> ans;
    auto g = [&](int x, int id) -> int { return (x >> id) & 1; };
    while (a != b && int(ans.size()) < 100) {
      int nv = 0;
      for (int j = 0; j < 30; j++) {
        int bit = g(b, j) ^ g(a, j);
        if ((nv | (bit << j)) > a) {
          continue;
        }
        nv |= bit << j;
      }

      a ^= nv;
      ans.push_back(nv);
    }

    if (a != b) {
      cout << "-1\n";
    } else {
      cout << ans.size() << '\n';
      for (int x : ans) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}
