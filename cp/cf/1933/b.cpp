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
    bool check = false;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= 3;
      if(a[i] == 1)
        check = true;
      (sum += a[i]) %= 3;
    }
    if(sum == 0) {
      cout << "0\n";
    }
    else if(sum == 2 || (sum == 1 && check)) {
      cout << "1\n";
    }
    else {
      cout << "2\n";
    }
  }
}


