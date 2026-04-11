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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    set<array<int, 4>> cands;
    cands.insert({a[0], 0, a[0], a[0]});
    cands.insert({x - a[n - 1], x, a[n - 1], a[n - 1]});
    for (int i = 0; i + 1 < n; i++) {
    }
  }
}
