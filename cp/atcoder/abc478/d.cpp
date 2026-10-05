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
  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, int>>> p(q);
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    x -= 1;
    l -= 1;
    r -= 1;
    p[x].push_back({l, r});
  }

  vector<int> ans(n);
  for (auto &r : p) {
    if (r.size() == 0) {
        continue;
    }
    sort(r.begin(), r.end());
    vector<pair<int, int>> di;
    di.push_back(r[0]);
    for (int i = 1; i < int(r.size()); i++) {
      auto [lo, hi] = r[i];
      if (lo <= di.back().second) {
        di.back().second = max(hi, di.back().second); 
      } else {
        di.push_back({lo, hi});
      }
    }

    for (auto [lo, hi] : di) {
      ans[lo] += 1;
      if (hi + 1 < n)
        ans[hi + 1] -= 1;
    }
  }

  for (int i = 0; i < n; i++) {
    if (i > 0)
      ans[i] += ans[i - 1]; 
    cout << ans[i] << " \n"[i == n - 1];
  }
}
