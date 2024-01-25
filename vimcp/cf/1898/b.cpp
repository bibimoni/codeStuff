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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n];
    int ans = 0, curr;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    curr = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
      if(a[i] > curr) {
        int k = (a[i] - 1) / curr + 1;
        curr = a[i] / k;
        ans += (k - 1);
      }
      else {
        curr = a[i];
      }
    }
    cout << ans << '\n';
  }
}


