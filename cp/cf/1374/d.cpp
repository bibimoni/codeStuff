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
    int n, k;
    cin >> n >> k;  
    int a[n];
    map<int, int, greater<int>> cnt;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(a[i] % k == 0)
        continue;
      cnt[k - a[i] % k]++;
    }
    int ans = 0, maxRem = -1;
    for(auto [_, s] : cnt) {
      ans = max(k * (s - 1), ans);
    }
    for(auto [f, s] : cnt) {
      if(k * (s - 1) == ans) {
        maxRem = max(maxRem, f);
      }
    }
    ans += maxRem + 1;
    cout << ans << '\n';
  }
}


