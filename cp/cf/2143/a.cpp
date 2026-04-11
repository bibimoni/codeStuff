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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }

    int mid = max_element(p.begin(), p.end()) - p.begin();
    int l = mid - 1, r = mid + 1;
    bool ok = true;
    int cur = n - 1;
    while (l >= 0 || r < n) {
      bool has = false;
      if (l >= 0 && p[l] == cur) {
        l -= 1;
        cur -= 1;
        has = true;
      }
      if (r < n && p[r] == cur) {
        r += 1;
        cur -= 1;
        has = true;
      }
      ok &= has;
      if (!has) {
        break;
      }
    }

    cout << (ok ? "Yes\n" : "No\n");
  }
}
