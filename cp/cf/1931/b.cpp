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
    int sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    int t = sum / n;
    int curr = 0;
    bool ok = true;
    for(int i = 0; i < n; i++) {
      if(t < a[i]) {
        curr += a[i] - t;
      }
      if(t > a[i]) {
        if(curr - (t - a[i]) < 0) {
          ok = false;
          break;
        }
        else {
          curr -= (t - a[i]);
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  } 
}


