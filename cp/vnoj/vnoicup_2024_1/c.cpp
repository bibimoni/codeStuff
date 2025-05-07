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
    // Try(0, x, {});
    vector<int> ans;
    int curr = 0;
    for(int i = 0; i < 31; i++) {
      vector<int> tmp;
      int curr = (1ll << i) - 1;
      for(int j = 0; j < 31; j++) {
        if((curr >= (1ll << j)) && ((curr ^ (1ll << j)) <= x)) {
          tmp.push_back(curr ^ (1ll << j));
        }
      }
      if(tmp.size() > ans.size()) {
        ans = tmp;
      }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " \n"[i == ans.size() - 1];
    }
  }
}


