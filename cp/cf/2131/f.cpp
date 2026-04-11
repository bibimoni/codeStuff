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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;

    vector<int> ca1(n + 1), cb1(n + 1);
    vector<int> ca0(n + 1), cb0(n + 1);
    for (int i = 1; i <= n; i++) {
      ca1[i] = ca1[i - 1] + int(a[i] == '1');
      cb1[i] = cb1[i - 1] + int(b[i] == '1');
      ca0[i] = ca0[i - 1] + int(a[i] == '0');
      cb0[i] = cb0[i - 1] + int(b[i] == '0');
    }

    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    vector<int> diff(n + 1);
    for (int i = 1; i <= n; i++) {
      diff[i] = cb0[i] - cb1[i];
    }

    sort(p.begin() + 1, p.end(),
         [&](int i, int j) { return diff[i] < diff[j]; });

    vector<int> nb1(n + 1);
    vector<int> nb0(n + 1);
    for (int i = 1; i <= n; i++) {
      nb1[i] = nb1[i - 1] + cb1[p[i]];
      nb0[i] = nb0[i - 1] + cb0[p[i]];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int a1 = ca1[i], a0 = ca0[i];
      int cmp = a1 - a0;
      int lo = 1, hi = n, ret = n + 1;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (cmp <= diff[p[mid]]) {
          hi = mid - 1;
          ret = mid;
        } else {
          lo = mid + 1;
        }
      }

      ans += (ret - 1) * ca0[i] + nb0[ret - 1];
      ans += (n - ret + 1) * ca1[i] + nb1[n] - nb1[ret - 1];
    }

    cout << ans << '\n';
  }
}
