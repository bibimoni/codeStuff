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
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (k > 1) {
      cout << "YES\n";
    } else {
      int val = a[j - 1];
      sort(a.begin(), a.end());
      cout << (val == a[n - 1] ? "YES\n" : "NO\n");
    }
  }
}
