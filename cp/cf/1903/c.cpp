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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n + 1], pre[n + 1]; pre[0] = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    int cnt = 1, ans = pre[n];
    for(int i = 2; i <= n; i++) {
      int tmp = pre[n] - pre[i - 1];
      int cut = ans + tmp;
      if(cut > ans) {
        ans = cut;
        cnt++;
      }
      dbg(ans, cut, tmp);
    }
    cout << ans << '\n';
  }
}


