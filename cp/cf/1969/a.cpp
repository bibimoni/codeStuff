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
    set<int> was;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = n;
    for(int i = 1; i <= n; i++) {
      int cnt = 1;
      int u = a[i];
      while(u != i && cnt < 3) {
        cnt += (u != i);
        u = a[u];
      }
      ans = min(ans, cnt);
    }
    cout << ans << '\n';
  }
}


