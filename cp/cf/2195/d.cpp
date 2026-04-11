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
    int n;
    cin >> n;
    vector<int64_t> f(n);
    for (int i = 0; i < n; i++) {
      cin >> f[i];
    }

    int64_t S = (f[0] + f[n - 1]) / (n - 1);
    vector<int64_t> a(n);
    a[0] = (f[1] - f[0] + S) / 2;
    a[n - 1] = (S - f[n - 1] + f[n - 2]) / 2;
    for (int i = 1; i + 1 < n; i++) {
      a[i] = (f[i + 1] - 2 * f[i] + f[i - 1]) / 2;
    }

    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
}
