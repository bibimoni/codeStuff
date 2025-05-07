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
  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1), p(n + 1), b(n + 1), q(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> p[i] >> b[i] >> q[i];
  }
  auto check = [&] (int w) -> bool {
    int cost = x;
    for (int i = 1; i <= n; i++) {
      int min_cost = 4e18;
      for(int i_a = 0; i_a <= b[i]; i_a++) {
        // w <= i_s * a[i] + i_t * b[i]
        // w - i_s * a[i] <= i_t * b[i]
        // ceil(w - i_s * a[i]) / b[i] <= i_t
        if (i_a * a[i] >= w) {
          min_cost = min(min_cost, i_a * p[i]);
        } else {
          int i_b = (w - i_a * a[i] + b[i] - 1) / b[i];
          min_cost = min(min_cost, i_a * p[i] + i_b * q[i]);
        }
      }

      for(int i_b = 0; i_b <= a[i]; i_b++) {
        // w <= i_s * a[i] + i_t * b[i]
        // w - i_s * a[i] <= i_t * b[i]
        // ceil(w - i_s * a[i]) / b[i] <= i_t
        if (i_b * b[i] >= w) {
          min_cost = min(min_cost, i_b * q[i]);
        } else {
          int i_a = (w - i_b * b[i] + a[i] - 1) / a[i];
          min_cost = min(min_cost, i_a * p[i] + i_b * q[i]);
        }
      }

      cost -= min_cost;
      if (cost < 0) {
        return false;
      }
    }
    return true;
  };
  int lo = 0, hi = 1e12, ret= 0;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      lo = mid + 1;
      ret = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << ret << '\n';
}


