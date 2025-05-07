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
  int curr;
  vector<int> ans;
  while(true) {
    cin >> curr;
    ans.push_back(curr);
    if(!curr)
      break;
  } 
  reverse(ans.begin(), ans.end());
  for(int i : ans) {
    cout << i << '\n';
  }
}


