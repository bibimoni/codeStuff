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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n + 1], sum = 0; 
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    sort(a + 1, a + n + 1); 
    reverse(a + 1, a + n + 1);
    int ans = (sum - 1) / 2 + 1;
    sum /= 2;
    for(int i = 1; i <= n; i++) {
      if(sum <= 0) break;
      ans++;
      sum -= a[i];
    }
    cout << ans << '\n';
  }
}



