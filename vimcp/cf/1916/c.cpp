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
    int n; cin >> n;
    int a[n];
    int cnt = 0, currSum = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];  
      if(a[i] & 1) cnt++;
      currSum += a[i];
      if(i == 0) {
        cout << a[i] << ' ';
      }
      else {
        cout << currSum - (cnt / 3) - (cnt - cnt / 3) % 2 << ' ';
      }
    }
    cout << '\n';
  }
}


