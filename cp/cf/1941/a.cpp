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
    int n, m, k;
    cin >> n >> m >> k;
    int b[n], c[m];
    for(int &i : b) {
      cin >> i;
    }
    for(int &i : c) {
      cin >> i;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) 
      for(int j = 0; j < m; j++)
        if(b[i] + c[j] <= k)
          ans++;
    cout << ans << '\n';   
  }
}


