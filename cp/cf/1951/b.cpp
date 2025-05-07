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
    //7 2 727 10 12 13
    //
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    // max(1->{i-1}) < a[i] && find number of element smaller than a[i]
    // swap i < k || i > k
    // i < k -> a[i] > a[k] stop at min(a[far], a[i])
    // k < i -> won't happened
    int pos = -1;
    for(int i = 1; i < k; i++) {
      if(a[i] > a[k]) {
        pos = i;
        break;
      }
    }
    int ans = 0;
    {
      //case 1
      if(pos != -1) {
        swap(a[k], a[pos]);
        int cnt = (pos == 1 ? 0 : 1);
        for(int i = pos + 1; i <= n; i++) {
          if(a[i] > a[pos])
            break;
          cnt++;
        }
        dbg(pos);
        ans = cnt;
        swap(a[k], a[pos]);
      }
    }
    {
      //case 2
      swap(a[1], a[k]);
      int cnt = 0;
      for(int i = 2; i <= n; i++) {
        if(a[i] > a[1])
          break;
        cnt++;
      }
      ans = max(ans, cnt);
    }
    cout << ans << '\n';
  }
}


