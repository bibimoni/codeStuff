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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int l = 1, r = n, ret = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      bool ok = true;
      for(int id = 0, i = 0; i < mid; i++) {
        while(id + 1 < m && b[id] != a[i]) {
          id++;
        }
        if(a[i] != b[id]) 
          ok = false;
        id++;
      }
      if(ok) {
        l = mid + 1;
        ret = mid;
      }
      else {
        r = mid - 1;
      }
    }
    cout << ret << '\n';
  }
}


