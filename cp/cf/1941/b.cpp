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

const int INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; 
    cin >> n;
    int a[n];
    for(int &i : a) {
      cin >> i;
    }
    bool ok = true;
    for(int i = 0; i < n - 2; i++) {
      if(a[i] < 0) {
        ok = false;
        break;
      }
      a[i + 1] -= a[i] * 2   ;
      a[i + 2] -= a[i];
      a[i] = 0;
    }
    cout << (ok && !a[n - 1] && !a[n - 2] ? "YES\n" : "NO\n");
  }
}


