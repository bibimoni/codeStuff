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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> left, right;
    if(a == c || a == d || b == c || b == d) {
      cout << "NO\n";
    }
    else {
      auto inside = [&] (int l, int r, int x) -> bool {
        if(l > r)
          swap(l, r);  
        return l < x && x < r;
      };
      if((!inside(a, b, c) && inside(a, b, d)) || (!inside(a, b, d) && inside(a, b, c))) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
}


