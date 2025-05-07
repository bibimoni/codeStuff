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
    vector<int> a(n);
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pre[i] = (i == 0 ? 0 : pre[i - 1]) + a[i];
    }
    auto sum = [&] (int l, int r) {
      if (l == 0) {
        return pre[r];
      } 
      return pre[r] - pre[l - 1];
    };
    int pos = -1;
    for (int i = 1; i < n - 1; i++) {
      if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
        pos = i;
        break;
      }
    }
    assert(pos != -1);
    int j = pos - 1;
    int l, r;
    long double ans = sum(j, pos + 1) / (long double) (3);
    for (int i = pos + 1; i < n; i++) {
      for (int j = pos - 1; j >= 0; j--) {
        if (sum(j, i) / (long double)(i - j + 1) > ans) {
          l = j, r = i;
          ans = max(ans, sum(j, i) / (long double)(i - j + 1));
        }
      }
    }
    // dbg(l, r);
    cout << fixed << setprecision(9) << ans << '\n';
  }
}

