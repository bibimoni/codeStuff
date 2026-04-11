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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    bool ans = a[n - 1] == b[n - 1];
    for (int i = n - 1; i >= 0; i--) {
      if (b[i] == a[i] || (b[i] == (a[i] ^ a[i + 1])) ||
          (b[i] == (a[i] ^ b[i + 1]))) {
        continue;
      }
      ans = false;
      break;
    }

    cout << (ans ? "YES\n" : "NO\n");
  }
}
