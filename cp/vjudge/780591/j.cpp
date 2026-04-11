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

  int n, p;
  cin >> n >> p;
  vector<__int128_t> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    a[i] = (__int128_t)t;
  }

#define int __int128_t

  int pre = 0;
  int res = n;
  for (int i = 1; i <= n; i++) {
    if (p < pre + a[i]) {
      res = i - 1;
      break;
    }

    int sub = pre + (i - 1) * (a[i] - 1);

    if (p - sub < a[i]) {
      res = i - 1;
      break;
    }

    pre += a[i];
  }

  cout << (long long)res << endl;
}
