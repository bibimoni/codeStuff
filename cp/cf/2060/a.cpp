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
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> a(5);
    for (int k : {0, 1, 3, 4}) {
      cin >> a[k];
    }
    int v1 = a[0] + a[1];
    int v2 = a[3] - a[1];
    int v3 = a[4] - a[3];
    int ans = 0;
    for (int x : {v1, v2, v3}) {
      a[2] = x;
      int cnt = 0;
      for (int i = 2; i < 5; i++) {
        cnt += a[i] == a[i - 1] + a[i - 2];
      }
      ans = max(ans, cnt);
    }
    cout << ans << '\n';
  }
}


