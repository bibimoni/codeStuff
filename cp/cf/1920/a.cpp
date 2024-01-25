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
    int n; cin >> n;
    int left = 1, right = 1e9;
    vector<int> num;
    for(int i = 0; i < n; i++) {
      int a, k; cin >> a >> k;
      if(a == 3) {
        num.push_back(k);
      }
      else if(a == 1) {
        left = max(left, k);
      }
      else {
        right = min(right, k);
      }
    }
    int ans = right - left + 1;
    for(int i : num) {
      if(i <= right && i >= left) ans--;
    }
    cout << (ans < 0 ? 0 : ans) << '\n';
  }
}


