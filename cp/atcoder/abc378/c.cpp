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
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (!mp.count(x)) {
      cout << -1 << " \n"[i == n - 1];
    } else {
      cout << mp[x] << " \n"[i == n - 1];
    }
    mp[x] = i + 1;
  }
}


