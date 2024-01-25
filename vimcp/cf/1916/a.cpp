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
    int n, k; cin >> n >> k;
    int b[n];
    int num = -1, product = 1;
    for(int i = 0; i < n; i++) {
      cin >> b[i];
      product *= b[i];
    }
    if(2023 % product == 0 && product <= 2023) {
      num = 2023 / product;
    }
    if(num == -1) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
      cout << num << " ";
      for(int i = 1; i < k; i++) cout << "1 ";
        cout << '\n';
    }
  }
}


