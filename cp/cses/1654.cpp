/**
 * Author: distiled
 */
#include<bits/stdc++.h>
#include <cmath>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#define table(...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  const int lg = 20;
  int mx = 1 << lg;
  vector dpSub(mx, 0), dpSup(mx, 0);
  for (int v : x) {
    dpSub[v] += 1;
    dpSup[v] += 1;
  }
  for (int i = 0; i < lg; i++) {
    for (int mask = 0; mask < mx; mask++) {
      if (mask & (1 << i)) {
        dpSub[mask] += dpSub[mask ^ (1 << i)];
      } else {
        dpSup[mask] += dpSup[mask ^ (1 << i)]; 
      }
    }
  }

  // x | y == 0
  // bit i cua x bat => bit i cua y phai tat
  // bit i cua x tat => bit i cua y la sao cung dc
  // 01001110
  // ?0??000?
  // -> y la submask cua 11111111 ^ 01001110 = 10110001
  for (int v : x) {
    cout << dpSub[v] << " " << dpSup[v] << " " << n - dpSub[((1 << lg) - 1) ^ v] << "\n";
  }

}
