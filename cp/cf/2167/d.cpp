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

// Get primes not greater than n in O(nloglogn)
vector<int> getprimes(int n) {
  vector<int> p;
  vector<bool> is(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    if (is[i]) {
      p.push_back(i);
      for (int j = 2 * i; j <= n; j += i)
        is[j] = 0;
    }
  }
  return p;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto p = getprimes(100);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int ans = (int)1e18 + 1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int v : p) {
        if (gcd(x, v) == 1) {
          ans = min(ans, v);
          break;
        }
      }
    }

    cout << ans << '\n';
  }
}
