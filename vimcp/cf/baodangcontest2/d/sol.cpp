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
    int n, m, x; cin >> n >> m >> x;
    int edges = m / x;
    if(edges == n - 1) {
      cout << "SIMPLE\n";
    }
    else if(edges < n - 1) {
      cout << "INVALID\n";
    }
    else {
      cout << "COMPLICATED\n";
    }
  }
}

