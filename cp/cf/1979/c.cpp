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
    vector<int> k(n);
    for(int i = 0; i < n; i++) {
      cin >> k[i];
    }
    int div = k[0];
    for(int i = 0; i < n; i++) {
      div = div * k[i] / __gcd(div, k[i]);
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
      ans[i] = div / k[i];
    }
    int sum = accumulate(ans.begin(), ans.end(), 0ll);
    bool ok = true;
    for(int i = 0; i < n; i++) {
      if(k[i] * ans[i] <= sum) {
        ok = false;
        break;
      }
    }
    if(!ok) {
      cout << "-1\n";
    }
    else {
      for(int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
      }
    }
  }
}


