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
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    int l = 0, r = n - 1;
    while(l + 1 < n && a[l + 1] == a[0]) {
      l++;
    }
    while(r - 1 >= 0 && a[r - 1] == a[n - 1]) {
      r--;
    }
    dbg(l, r);
    if(a[0] == a[n - 1]) {
      ans = n - (l + 1 + n - r);
    }
    else {
      ans = min(n - (l + 1), n - (n - r));
    }
    cout << (ans < 0 ? 0 : ans) << '\n';
  } 
}


