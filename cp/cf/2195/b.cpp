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
// #define int int64_t

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

    vector<int> was(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      if (was[i]) {
        continue;
      }

      int cur = i + 1;
      was[cur - 1] = 1;
      vector<int> p{i};
      while (cur * 2 <= n) {
        was[cur * 2 - 1] = 1;
        p.push_back(cur * 2 - 1);
        cur *= 2;
      }

      auto q = p;
      sort(p.begin(), p.end(), [&](int u, int v) { return a[u] < a[v]; });
      for (int j = 0; j < int(q.size()); j++) {
        b[q[j]] = a[p[j]];
      }
    }

    cout << (is_sorted(b.begin(), b.end()) ? "YES\n" : "NO\n");
  }
}
