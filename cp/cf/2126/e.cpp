/**
 * Author: distiled
 */
#include <algorithm>
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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
      cin >> q[i];
    }

    if (n == 1) {
      cout << (p[0] == q[0] ? "Yes\n" : "No\n");
      continue;
    }

    bool ok = gcd(p[0], q[1]) == q[0] && gcd(p[n - 2], q[n - 1]) == p[n - 1];
    for (int i = 0; i < n; i++) {
      if (i < n - 1) {
        ok &= (p[i] % p[i + 1] == 0);
      } else if (i > 1) {
        ok &= (q[i] % q[i - 1] == 0);
      }
    }
    for (int i = 1; i < n - 1; i++) {
      ok &= (p[i] % gcd(p[i - 1], q[i])) == 0;
      ok &= (q[i] % gcd(q[i + 1], p[i])) == 0;
    }

    cout << (ok ? "Yes\n" : "No\n");
  }
}
