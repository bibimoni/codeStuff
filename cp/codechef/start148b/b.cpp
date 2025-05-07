// time-limit: 3000
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] -= 1;
    }
    vector<array<int, 3>> cnt(n + 1, {0, 0, 0});
    vector<int> pre(n + 1, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] | (1 << a[i]);
      for (int k = 0; k < 3; k++) {
        cnt[i][k] = cnt[i - 1][k] + (a[i] == k);
      }
    }
    for (int i = n; i >= 0; i--) {
      suf[i] = suf[i + 1] | (1 << a[i]);
    }
    auto siz = [&] (int num) -> int {
      return ((num >> 1) & 1) + ((num >> 2) & 1) + ((num >> 0) & 1);
    };
    auto idx = [&] (int i, int cn) -> int {
      int l = 1, r = i, ret = 0;
      while (l <= r) {
        int m = (l + r) >> 1;
        int c0 = cnt[i][0] - cnt[m - 1][0];
        int c1 = cnt[i][1] - cnt[m - 1][1];
        int c2 = cnt[i][2] - cnt[m - 1][2];
        int tmp = (c0 == 0 ? 0 : 1) | (c1 == 0 ? 0 : 2) | (c2 == 0 ? 0 : 4);
        int sz = siz(tmp);
        if (sz >= cn) {
          l = m + 1;
          if (sz == cn) {
            ret = m;
          }
        } else {
          r = m - 1;
        }
      }
      return ret;
    };
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int nxt = i;
      for (int k = 1; k <= 3; k++) {
        int id = nxt;
        if (id == 0) {
          continue;
        }
        if (k == 3) {
          ans += id;
          break;
        }
        int lid = idx(i, k + 1);
        nxt = lid;
        // int tmp = st.query(lid + 1, i);
        int c0 = cnt[i][0] - cnt[lid][0];
        int c1 = cnt[i][1] - cnt[lid][1];
        int c2 = cnt[i][2] - cnt[lid][2];
        int tmp = (c0 == 0 ? 0 : 1) | (c1 == 0 ? 0 : 2) | (c2 == 0 ? 0 : 4);
        int nt = 0;
        for (int j = 0; j < 3; j++) {
          if ((tmp >> j) & 1) {
            nt |= (1ll << ((j + 1) % 3));
          }
        }
        int lret = -1, rret = -1;
        {
          int l = lid + 1, r = id;
          while (l <= r) {
            int m = (l + r) >> 1;
            int ns = 0;
            ns |= pre[m - 1] | suf[i + 1];
            if ((ns | nt) == 7) { // 7 = 111b
              r = m - 1;
              lret = m;
            } else {
              l = m + 1;
            }
          }  
        }
        if (lret != -1) {
          ans += id - lret + 1;
        }
      }
    }
    cout << ans << '\n';
  }
}


