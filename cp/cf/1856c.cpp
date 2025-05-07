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
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    if(n == 1) {
      cout << "0\n";
      continue;
    }
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1; i < n; i++) {
      if(a[i] < a[i - 1]) {
        ans = max(ans, a[i - 1]);
      }
    }
    cout << ans << '\n';
  }
}

