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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    int ans = 0;
    int curr = 0;
    for(int i = 1; i <= n; i++) {
      curr = max(curr, a[i]);
      ans += (curr * 2 == pre[i]);
    }
    cout << ans << '\n';
  }
}


