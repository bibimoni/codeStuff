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
  int n, k;
  cin >> n >> k;
  vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    cin >> a[i];
  }

  int N = 1 << n;
  auto find_in = [&](int s, int seg) -> pair<int, int> {
    return pair<int, int>{seg * (1 << s), (seg + 1) * (1 << s) - 1};
  };

  vector<int> ans(N);
  for (int s = 1; s <= n; s++) {
    vector<int> cur_e;
    int i = 0;
    int cnt = 0;
    while (i < N) {
      vector<int> tmp(1 << s);
      iota(tmp.begin(), tmp.end(), i);
      sort(tmp.begin(), tmp.end(), [&](int u, int v) { return a[u] < a[v]; });

      int smaller_in = 0;
      for (int j = 0; j < (1 << s); j++) {
        int jj = tmp[j];
        int seg = cnt;
        int smaller_out = a[jj] - 1 - smaller_in;
        int can = smaller_in + min(k, smaller_out);
        auto [l, r] = find_in(s, seg);
        if (can >= r - l) {
          ans[jj] = s;
        }
        smaller_in += 1;
      }
      i += (1 << s);
      cnt += 1;
    }
  }

  for (int x : ans) {
    cout << x << ' ';
  }
}
