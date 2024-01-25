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
    int n, k, d; cin >> n >> k >> d;
    int a[n + 1], b[k + 1], ans = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    //use 1 days to get the current state and (d - 1) / 2 will have a[1] = 1    
    for(int i = 1; i <= k; i++) {
      cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
      ans += (a[i] == i);
    }
    ans += (d - 1) / 2; 
    for(int i = 1; i <= min(d - 1, 2 * n); i++) {
      int id = i % k; if(id == 0) id = k;
      for(int j = 1; j <= b[id]; j++) {
        a[j]++;
      }
      int cnt = 0;
      for(int j = 1; j <= n; j++) {
        cnt += (a[j] == j);
      }
      ans = max(ans, cnt + (d - 1 - i) / 2);
    }
    cout << ans << '\n';
  }
}


