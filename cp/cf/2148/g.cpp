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

int main() {
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

    vector<vector<int>> pa(n);
    for (int i = 0; i < n; i++) {
      int x = a[i];
      for (int j = 1; j * j <= x; j++) {
        if (x % j == 0) {
          pa[i].push_back(j);
          if (j * j != x) {
            pa[i].push_back(x / j);
          }
        }
      }
    }

    vector<int> ans;
    vector<int> cntp(n + 1);

    auto add = [&](int p) -> void {
      if (cntp[p] == 0) {
      } else {
      }
      cntp[p] += 1;
    };

    for (int i = 0; i < n; i++) {
      for (auto p : pa[i]) {
        add(p);
      }
      int val = *sst.rbegin();
      auto it = sst.lower_bound(val);
      dbg(sst);
      if (it == sst.begin()) {
        ans.push_back(0);
        continue;
      }
      it--;
      if (val == *it) {
        ans.push_back(0);
      } else {
        ans.push_back(*it);
      }
    }

    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
}
