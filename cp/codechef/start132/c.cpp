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
    vector<int> a(n + 2);
    a[0] = a[n + 1] = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> pre(n + 2, 0);
    int rem = 0;
    for(int i = 1; i <= n + 1; i++) {
      pre[i] = (a[i - 1] & 1) * (pre[i - 1] + 1);
      if(a[i] % 2 == 0) {
        rem += pre[i] * (pre[i] + 1);
      }
    }
    int ans = n * (n + 1) - rem;
    vector<int> suf(n + 2, 0);
    for(int i = n; i >= 1; i--) {
      suf[i] = (a[i + 1] & 1) * (suf[i + 1] + 1);
    }
    for(int i = 1; i <= n; i++) {
      if(a[i] % 2 == 1) {
        int len = pre[i] + suf[i] + 1;
        int curr = rem - (len * (len + 1)) + (pre[i] * (pre[i] + 1)) + (suf[i] * (suf[i] + 1));
        ans = max(ans, n * (n + 1) - curr);
      }
    }
    cout << ans / 2 << '\n';
  }
}


