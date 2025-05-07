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
    vector<int> a(n);
    map<int, int> f;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(a[i] == 1) {
        f[1] += 1;
      }
      else {
        f[1] += a[i] - 2;
        f[2] += 1;
      }
    }
    int ans = 0;
    for(auto [_, v] : f) {
      ans += v / 2;
    }
    cout << ans << '\n';
  }
}


