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
    int n, x, y;
    cin >> n >> x >> y;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    const int MODX = (int) (1e9 + 7) * x, MODY = (int) (1e9 + 7) * y;
    int ans = 0;
    map<pair<int, int>, int> f;
    for(int i = 1; i <= n; i++) {
      ans += f[{((-a[i] + MODX) % x), ((a[i] + MODY) % y)}];
      f[{((a[i] + MODX) % x), ((a[i] + MODY) % y)}]++;
    }
    cout << ans << '\n';
  }
}


