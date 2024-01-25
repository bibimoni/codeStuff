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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n];
    int neg = 0, id = 0, zero = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(a[i] != 0) {
        id = i;
      }
      if(a[i] == 0) {
        zero = 1;
      }
      if(a[i] < 0) neg ^= 1;
    }
    if(neg) {
      cout << "0\n";
    }
    else if(zero) {
      cout << "0\n";
    }
    else {
      cout << 1 << '\n' << id + 1 << ' ' << 0 << '\n';
    }
  }
}


