/**
 * Author: distiled
 */
#include<bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      seg[i] = {l, r};
    }
    sort(seg.begin(), seg.end());
    auto findAns = [&] (int ignore) -> int {
      map<int, int> cnt;
      int mx = 0, cur = 0;
      for (const auto &[l, r] : seg) {
        if (l == ignore || r == ignore) {
          continue;
        }
        cnt[l] += 1;
        cnt[r + 1] -= 1;
      }
      for (const auto& [idx, v] : cnt) {
        cur += v;
        mx = max(mx, cur);
      }
      return mx;
    };
    cout << max(findAns(1), findAns(m)) << '\n';
  }
}

