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
  int n, k;
  cin >> n >> k;
  vector<int> ans;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(x % k == 0)
      ans.push_back(x / k);
  }
  for(int e : ans) {
    cout << e << ' ';
  }
}


