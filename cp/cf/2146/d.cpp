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
    int l, r;
    cin >> l >> r;
    int bit = 0;
    int val = 1;
    for (int k = 0; k < 20; k++) {
      if (val * 2 <= r + 1) {
        val *= 2;
        bit += 1;
      }
    }

    int st = (1 << (bit)) - 1;
    vector<int> ans(r + 1);
    int cnt = r - st;
    dbg(st, cnt);
    for (int i = st - cnt + 1, j = r; i <= r; i++, j--) {
      ans[i] = j;
    }
    dbg(ans);
    for (int i = st - cnt, j = 0; i >= 0; i--, j++) {
      ans[i] = j;
    }

    cout << (r + 1) * r << '\n';
    int sum = 0;
    for (int i = 0; i < r + 1; i++) {
      sum += ans[i] | i;
      cout << ans[i] << " \n"[i == r];
    }
    dbg(ans, sum);
    assert((r + 1) * r == sum);
  }
}
