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
  int n;
  cin >> n;
  int a[n];
  for(int &i : a) {
    cin >> i;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i != j) {
        int or2 = a[i] | a[j];
        int or1 = 0;
        for(int k = 0; k < n; k++) {
          if(i != k && j != k) {
            or1 |= a[k];
          }
        }
        if(or1 == or2) {
          ans++;
        }
      }
    }
  }
  cout << ans;
}


