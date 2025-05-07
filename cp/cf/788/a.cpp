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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> p(n);
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + abs(a[i + 1] - a[i]) * (i % 2 ? 1 : -1);
  }
  const int INF = int(1e9);
  int ans = 0, lo = 0, hi = -INF;
  for (int i = 1; i < n; i++) {
    lo = min(lo, p[i]);
    hi = max(hi, p[i]);
  }
  ans = hi - lo;
  cout << ans << '\n';
}

