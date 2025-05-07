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
    int n, x;
    cin >> x >> n;
    vector<int> divs;
    for(int i = 1; i * i <= x; i++) {
      if(x % i == 0) {
        divs.push_back(i);
        if(x / i != i) {
          divs.push_back(x / i);
        }
      }
    }
    sort(divs.begin(), divs.end());
    int ans = 1;
    for(int i : divs) {
      if(i <= (int) (x / n)) {
        ans = i;
      }
    }
    cout << ans << '\n';
  }
}


