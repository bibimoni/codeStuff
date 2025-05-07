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
  int n; cin >> n;
  vector<int> ans;
  n--;
  while(n) {
    ans.push_back(n % 5);
    n /= 5;
  }  
  reverse(ans.begin(), ans.end());
  int res = 0;
  for(int i : ans) {
    res = res * 10 + i;
  }  
  cout << res * 2;
}


