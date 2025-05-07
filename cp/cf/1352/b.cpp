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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k; cin >> n >> k;
    if(n < k) {
      cout << "NO\n";
      continue;
    }
    //k
    //1 (n - 1) / k - 1
    //1 1 (n - 2) / (k - 2)

    //2 (n - 2) / k - 1
    bool ok = false;
    for(int i = 1; i <= k; i++) {
        //dbg(n, n - k + i, i);
      if(n - k + i<= 0) continue;
      if((n - k + i) % i == 0 && ((n - k + i) / i) % 2 == 1) {
        cout << "YES\n";
        for(int j = 1; j <= i; j++) cout << ((n - k + i) / i) << ' ';
        for(int j = 1; j <= k - i; j++) cout << "1 ";
        cout << '\n';
        ok = true;
        break;
      }
    }
    if(ok) continue;
    for(int i = 1; i <= k; i++) {
        //dbg(n, n - k + i, i);
      if(n - k * 2 + i * 2 <= 0) continue;
      if((n - k * 2 + i * 2) % i == 0 && ((n - k * 2 + i * 2) / i) % 2 == 0) {
        cout << "YES\n";
        for(int j = 1; j <= i; j++) cout << ((n - k * 2 + i * 2) / i) << ' ';
        for(int j = 1; j <= k - i; j++) cout << "2 ";
        cout << '\n';
        ok = true;
        break;
      }
    }
    if(!ok) {
      cout << "NO\n";
    }
  }
}

