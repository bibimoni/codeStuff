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
    int n;
    cin >> n;
    int a[2 * n];
    for(int i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    sort(a, a + 2 * n);
    int ans = 0;
    for(int i = 0; i < 2 * n; i += 2) {
      ans += min(a[i], a[i + 1]);
    }
    cout << ans << '\n';
  }
}


