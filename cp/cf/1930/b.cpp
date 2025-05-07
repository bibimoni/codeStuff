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
    vector<int> ans(n);
    int k = 1;
    for(int i = 0; i < n; i += 2) {
      ans[i] = k++;
    }    
    k = n;
    for(int i = 1; i < n; i += 2) {
      ans[i] = k--;
    }
    for(int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}


