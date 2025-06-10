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
    int n, m;
    cin >> n >> m;
    if (m % n != 0 || m < n) {
      cout << "-1\n";
      continue;
    }
    if (n == m) {
      cout << "0\n";
      continue;
    }
    if (n == 1) {
      cout << (m == 1 ? "1 1" : "-1") << '\n';
      continue;
    }
    vector<int> ans;
    while (n < m) {
      if (m % n != 0) {
        break;
      }
      int x = m / n;
      int g = __gcd(n, x);
      if (g == 1 && x > 1) {
        break;
      }
      n *= g;
      ans.push_back(g);
    }
    if (n == m) {
      cout << ans.size() << ' ';
      for (int x : ans) {
        cout << x << ' ';
      }
      cout << '\n';
    } else {
      cout << "-1\n";
    }
  }
}
