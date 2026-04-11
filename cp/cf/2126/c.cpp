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
    int n, k;
    cin >> n >> k;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> h[i];
    }

    int before = h[k];
    sort(h.begin() + 1, h.end());
    h.erase(unique(h.begin() + 1, h.end()), h.end());
    int start = -1;
    n = h.size() - 1;
    for (int i = 1; i <= n; i++) {
      if (h[i] == before) {
        start = i;
        break;
      }
    }
    assert(start != -1);

    if (start == n) {
      cout << "Yes\n";
      continue;
    }

    int water = 1;
    bool ok = true;
    for (int i = start; i < n; i++) {
      int rem = h[i] - water + 1;
      int has = h[i + 1] - h[i];
      if (rem >= has) {
        water += h[i + 1] - h[i];
      } else {
        ok = false;
        break;
      }
    }

    cout << (ok ? "Yes\n" : "No\n");
  }
}
