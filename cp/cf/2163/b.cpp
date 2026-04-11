/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <utility>
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
    vector<int> a(n + 1);
    vector<int> id(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      id[a[i]] = i;
    }

    string x;
    cin >> x;
    x = " " + x;

    vector<pair<int, int>> ops;
    if (id[1] > 1) {
      ops.push_back({1, id[1]});
    }
    if (id[n] > 1) {
      ops.push_back({1, id[n]});
    }
    if (id[1] < n) {
      ops.push_back({id[1], n});
    }
    if (id[n] < n) {
      ops.push_back({id[n], n});
    }
    ops.push_back({min(id[n], id[1]), max(id[n], id[1])});

    string s = string(n + 1, '0');
    for (auto [l, r] : ops) {
      int mx = max(a[l], a[r]);
      int mn = min(a[r], a[l]);
      dbg(l, r, mx, mn);
      for (int i = l + 1; i < r; i++) {
        if (s[i] == '0')
          s[i] = (mx > a[i] && mn < a[i] ? '1' : '0');
      }
    }
    dbg(s);

    bool ok = true;
    for (int i = 1; i <= n; i++) {
      ok &= ((x[i] == '1' && s[i] == '1') || x[i] == '0');
    }

    if (ok) {
      cout << ops.size() << '\n';
      for (auto [l, r] : ops) {
        cout << l << ' ' << r << '\n';
      }
    } else {
      cout << "-1\n";
    }
  }
}
