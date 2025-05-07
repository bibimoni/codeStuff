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
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto check = [&] (char b) -> int {
      int ret = 0;
      for(int i = 0; i < n; i++) {
        if(a[i][0] == b) {
          ret++;
          break;
        }
      }
      for(int i = 0; i < n; i++) {
        if(a[i][m - 1] == b) {
          ret++;
          break;
        }
      }
      for(int i = 0; i < m; i++) {
        if(a[0][i] == b) {
          ret++;
          break;
        }
      }
      for(int i = 0; i < m; i++) {
        if(a[n - 1][i] == b) {
          ret++;
          break;
        }
      }
      return ret;
    };
    cout << (check('W') == 4 || check('B') == 4 ? "YES\n" : "NO\n");
  }
}


