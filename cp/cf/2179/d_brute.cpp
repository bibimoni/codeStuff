/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
    vector<int> p(1 << n);

    iota(p.begin(), p.end(), 0);
    auto cmp = [&](auto &k, auto &j) -> bool {
      if (k.size() == 0) {
        return true;
      }
      for (int i = 0; i < (1 << n); i++) {
        if (k[i] > j[i]) {
          dbg(i);
          return true;
        } else {
          return false;
        }
      }
      return false;
    };
    int best = 0;
    // p = {7, 5, 4, 6, 0, 1, 2, 3};
    vector<int> ans;
    do {
      int cur = p[0], sum = 0;
      for (int i : p) {
        cur &= i;
        // dbg(__builtin_popcount(cur));
        sum += __builtin_popcount(cur);
      }
      if (sum > best) {
        ans = p;
        best = sum;
      }
      if (sum == best) {
        if (cmp(ans, p)) {
          dbg(p, ans, cur, sum);
          ans = p;
        }
      }
    } while (next_permutation(p.begin(), p.end()));

    dbg(best, ans);
  }
}
