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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      p[i] = p[i - 1] + a[i];
    }
    auto range = [&] (int shift, int l, int r) -> int {
      shift = (shift == 1 ? 1 : n - shift + 2);
      if (r < shift) {
        shift -= 1;
        int take_r = shift - r + 1;
        int take_l = shift - l + 1;
        return p[n - take_r + 1] - p[n - take_l];
      } else if (l >= shift) {
        shift -= 1;
        return p[r - shift] - p[l - shift - 1];
      } else {
        shift -= 1;
        int take = shift - l + 1;
        return p[n] - p[n - take] + p[r - shift];
      }
    }; 
    while (q--) {
      int l, r;
      cin >> l >> r;
      int c_l = (l / n) + (l % n != 0);
      int c_r = (r / n) + (r % n != 0);
      l -= (c_l - 1) * n;
      r -= (c_r - 1) * n;
      int mid = c_r - c_l - 1;
      if (c_l == c_r) {
        cout << range(c_l, l, r) << '\n';
      } else {
        cout << range(c_l, l, n) + range(c_r, 1, r) + mid * p[n] << '\n';
      }
    }
  }
}


