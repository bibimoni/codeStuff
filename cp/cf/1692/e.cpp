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
    int n, s;
    cin >> n >> s;
    int a[n + 1];
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      pref[i] = pref[i - 1] + a[i];
    }
    map<int, int> f;
    int ans = n + 1;
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
      if(pref[i] >= s && f.count(pref[i] - s)) {
        ans = min(ans, n - (i - f[pref[i] - s]));
      }
      if(a[i] == 1) {
        f[pref[i]] = i;
      }
    }
    cout << (ans == n + 1 ? -1 : ans) << '\n';
  }
}


