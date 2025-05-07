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
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    rotate(p.begin(), p.begin() + 2, p.end());    
    reverse(p.begin() + n - 2, p.end());
    if(n == 3) {
      cout << "-1\n";
    }
    else {
      for(int i : p) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
    }
  }
}


