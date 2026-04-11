/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <cmath>
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
  freopen("defining_prizes_validation_input.txt", "r", stdin);
  freopen("defining_prizes_validation_output.txt", "w", stdout);
  int tt;
  cin >> tt;
  for (int ttt = 1; ttt <= tt; ttt++) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> bb(m);
    for (int i = 0; i < m; i++) {
      cin >> bb[i];
    }

    sort(a.begin(), a.end());
    sort(bb.begin(), bb.end(), greater<>());
    // dbg(a);

    vector<int> last;
    auto check = [&](int mid) -> bool {
      auto b = bb;
      vector<int> need{mid};
      for (int i = n - mid + 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
          need.push_back(n - i);
        }
        // dbg(i, need, mid, a);
      }
      int j = 0, cur_need = need[j];
      for (int i = 0; i < m && j < int(need.size()); i++) {
        dbg(i, j, need);
        if (need[j] == 0) {
          j += 1;
          if (j < int(need.size()))
            cur_need = need[j];
        }
        if (j >= int(need.size())) {
          break;
        }
        if (need[j] <= b[i]) {
          int range = cur_need - need[j];
          b[i] -= need[j];
          need[j] = 0;
          j += 1;
          if (j < int(need.size())) {
            cur_need = need[j];
            int can = min(b[i], range);
            need[j] -= min(need[j], can);
          }
        } else {
          if (j < int(need.size())) {
            need[j] -= b[i];
          }
        }
      }
      if (j < int(need.size()) && need[j] == 0) {
        j += 1;
      }
      bool ok = true;
      for (int i = 0; i < int(need.size()); i++) {
        ok &= need[i] <= 0;
      }
      last = need;

      return j >= (int)need.size() && ok;
    };

    vector<int> cands;
    for (int i = n - 1; i > 0; i--) {
      if (a[i] != a[i - 1]) {
        cands.push_back(n - i);
      }
    }
    cands.push_back(n);
    // reverse(cands.begin(), cands.end());
    dbg(cands, a);
    // dbg(cands);

    int lo = 0, hi = cands.size() - 1, ret = 0;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      dbg(mid);
      if (check(cands[mid])) {
        lo = mid + 1;
        ret = cands[mid];
      } else {
        hi = mid - 1;
      }
    }

    cout << "Case #" << ttt << ": " << ret << '\n';
  }
}
