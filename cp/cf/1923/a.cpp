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
    int a[n];
    int ans = 0;
    bool meet = false;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(a[i] == 1) {
        meet = true;
      }
      if(meet && a[i] == 0) {
        ans++;
      }
    }
    for(int i = n - 1; i >= 0; i--) {
      if(a[i] == 0) {
        ans--;
      }
      else {
        break;
      }
    }
    cout << ans << '\n';
  }
}


