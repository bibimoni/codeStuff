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
    int a, b, c;
    cin >> a >> b >> c;
    if((a + b) >= 10 || (a + c) >= 10 || (b + c) >= 10) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}

