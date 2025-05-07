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
    vector<int> arr;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = true;
    int prev = 99;
    for(int i = n - 1; i >= 0; i--) {
      if(a[i] <= prev) {
        prev = a[i];
      }
      else {
        int f = a[i], s = a[i] % 10;
        f /= 10;
        if(a[i] < 10 && a[i] > prev) {
          ok = false;
          break;
        }
        if(a[i] < 10 && a[i] <= prev) {
          continue;
        }
        if(f > s || s > prev) {
          ok = false;
          continue;
        }
        else {
          prev = f;
        }
      }
      dbg(prev);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


