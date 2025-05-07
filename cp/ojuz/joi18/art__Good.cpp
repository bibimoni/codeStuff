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
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int ans = 0;
  int best = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int cur = 0, mn = 1e18, mx = -1e18;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        cur += b[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
      }
    }
    if (mn != int(1e18) || mx != int(-1e18)) {
      if (ans < cur - (mx - mn)) {
        ans = max(ans, cur - (mx - mn));
        best = mask;
      }
    }
  }
  cout << bitset<13>(best).to_string() << '\n';
  cout << ans << '\n';
}

