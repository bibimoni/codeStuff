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
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    struct ST {
      map<int, int> mp;
      int cur = 0;
      int add(int x) {
        mp[x] += 1;
        cur += int(mp[x] == 1);
        return cur;
      }
      int rem(int x) {
        mp[x] -= 1;
        cur -= int(mp[x] == 0);
        return cur;
      }
    };

    int ans = 0;
    int j1 = 1, j2 = 1;
    ST st1, st2;
    for (int i = 1; i <= n; i++) {
      st1.add(a[i]);
      st2.add(a[i]);
      while (j1 < i && st1.cur >= k) {
        st1.rem(a[j1]);
        j1 += 1;
      }
      if (j1 > 1 && st1.cur < k) {
        j1 -= 1;
        st1.add(a[j1]);
      }
      while (j2 < i && st2.cur > k) {
        st2.rem(a[j2]);
        j2 += 1;
      }

      assert(j2 <= j1);
      if (st1.cur == k && st2.cur == k) {
        int pl = i - l + 1;
        int pr = i - r + 1;
        if (pr > j1 || j2 > pl) {
          continue;
        }
        pl = min(pl, j1);
        pr = max(pr, j2);
        ans += pl - pr + 1;
      }
    }

    cout << ans << '\n';
  }
}
