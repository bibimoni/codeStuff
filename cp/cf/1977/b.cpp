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
    int x;
    cin >> x;
    vector<int> ans;
    while(x) {
      if(x % 2 == 0) {
        ans.push_back(0);
      }
      else if((x & 1) && ((x >> 1) & 1 ^ 1) || x == 1) {
        ans.push_back(1);
        x--;
      }
      else {
        ans.push_back(-1);
        x++;
      }
      x /= 2;
    }
    cout << ans.size() << '\n';
    for(int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}


