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
  int n, q;
  cin >> n >> q;
  vector<int> cnt(n + 1, 1);
  int cur = 1;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int ret = 0;
    while (cur <= x) {
      ret += cnt[cur];
      cur += 1;
    }
    cnt[y] += ret;
    cout << ret << '\n';
  }
}
