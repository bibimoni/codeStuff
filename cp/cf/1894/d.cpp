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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n, m; cin >> n >> m; 
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i]; 
    sort(b, b + m, greater<int>());
    int i = 0, j = 0;
    for(int i = 0; i < n; i++) {
      while(j < m && b[j] >= a[i]) {
        cout << b[j++] << ' ';
      }
      cout << a[i] << ' ';
    }
    while(j < m) {
      cout << b[j++] << ' ';
    }
  }
}


