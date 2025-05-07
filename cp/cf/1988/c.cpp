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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> ans;
    int curr = n;
    for (int j = 60; j >= 0; j--) {
      if ((n >> j) & 1) {
        if ((curr ^ (1ll << j)) > 0) {
          ans.push_back(curr ^ (1ll << j));
        }
      }
    }
    ans.push_back(n);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " \n"[i == ans.size() - 1];
    }
  }
}


