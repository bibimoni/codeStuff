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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> pXor(n + 1, 0), p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pXor[i] = pXor[i - 1] ^ a[i];
      p[i] = p[i - 1] + a[i];
    }
    int lt, rt;
    cin >> lt >> rt;
    auto range = [&] (int l, int r) -> int {
      return (p[r] - p[l - 1]) - (pXor[r] ^ pXor[l - 1]);
    };
    auto cmp = [&] (pair<int, int> i, pair<int, int> j) -> pair<int, int> {
      if (i.second - i.first < j.second - j.first) {
        return i;
      }
      return j;
    };
    pair<int, int> ans = {1, n};
    int val = range(1, n);
    for (int i = 1; i <= n; i++) {
      int l = i, r = n;
      if (range(i, n) < val) {
        continue;
      }
      while (l <= r) {
        int m = (l + r) >> 1;
        if (range(i, m) == val) {
          ans = cmp(ans, {i, m});          
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }
    cout << ans.first << ' ' << ans.second << '\n';
  }
}

