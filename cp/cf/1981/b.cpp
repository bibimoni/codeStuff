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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    if(m == 0) {
      cout << n << '\n';
      continue;
    }
    function<int(int, int)> cnt = [&] (int bound, int k) {
      bound++;
      int t = (1ll << k);
      int ret = ((bound / t) / 2 * t);
      if(((bound / t) & 1)) {
        ret += ((bound) - ((bound / t) * (t)));
      }
      return ret;
    };
    function<int(int, int, int)> get = [&] (int l, int r, int k) {
      return cnt(r, k) - (l - 1 < 0 ? 0 : cnt(l - 1, k));
    };
    int ans = n;
    for(int j = 0; j <= 60; j++) {
      int up = n + m, down = max(0ll, n - m);
      if(get(down, up, j))
        ans |= (1ll << j);
    }
    cout << ans << '\n';
  }
}


