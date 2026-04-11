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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, w;
    cin >> n >> w;
    vector<int> c(n);
    vector<int64_t> sum_mod(2 * w);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      sum_mod[i % (2 * w)] += c[i];
    }

    for (int i = 1; i < 2 * w; i++) {
      sum_mod[i] += sum_mod[i - 1];
    }

    int64_t ans = sum_mod[w - 1];
    auto range = [&](int l, int r) -> int64_t {
      if (r < l) {
        return sum_mod[r] + sum_mod[2 * w - 1] - (l > 0 ? sum_mod[l - 1] : 0);
      }
      return sum_mod[r] - (l > 0 ? sum_mod[l - 1] : 0);
    };
    for (int i = 0; i < 2 * w; i++) {
      ans = min(ans, range((i - w + 2 * w + 1) % (2 * w), i));
    }

    cout << ans << '\n';
  }
}
