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
  int n, s;
  cin >> n >> s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n, ans = 0, c = 0;
  while (l <= r) {
    int m = (l + r) >> 1;
    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++) {
      cost[i] = a[i] + i * m;
    }
    sort(cost.begin() + 1, cost.end());
    int v = accumulate(cost.begin() + 1, cost.begin() + m + 1, 0ll);
    if (v <= s) {
      l = m + 1;
      ans = m;
      c = v;
    } else {
      r = m - 1;
    }
  }
  cout << ans << ' ' << c << '\n';
}