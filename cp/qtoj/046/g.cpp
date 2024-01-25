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
  set<int> sq;
  for(int i = 0; i * i * i * i <= (int) 1e18; i++) {
    sq.insert(i * i);
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int cnt = sqrt(n);
    for(int i : sq) {
      if(n % i == 0) {
        dbg(i);
      }
      if(n % i == 0 && sq.find(n / i) != sq.end()) {
        dbg(n / i);
        cnt--;
      }
    }
    cout << cnt << '\n';
  }
}

