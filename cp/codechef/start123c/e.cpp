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
    int n, a, b;
    cin >> n >> a >> b;
    if(n % (a + b + 1) == 0) {
      cout << "Alice\n";
    }
    else {
      cout << "Bob\n";
    }
    
  }
}

