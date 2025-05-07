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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m; cin >> n >> m;
    int a[n + 1], b[m + 1];
    int sumA = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      sumA += a[i];
    }
    for(int i = 1; i <= m; i++) {
      cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m, greater<int>());
    int ans = 0, i2 = m;
    for(int i = 1; i <= n; i++) {
      ans += abs(a[i] - b[i]);
    }
    for(int i = n; i >= 1; i--) {
      ans += abs()
    }
    cout << ans << '\n';
  }
}


