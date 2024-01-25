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
  vector<array<int, 3>> ans;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      for(int k = 0; k <= n; k++) {
        if(i + j + k <= n) ans.push_back({i, j, k});
      }
    }
  }
  for(auto[i1, i2, i3] : ans) cout << i1 << ' ' << i2 << ' ' << i3 << '\n';
}


