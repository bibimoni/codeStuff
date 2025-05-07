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
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i];
    }
    int ans = -1e18;
    bool found = false;
    for(int i = 1; i <= n; i++) {
      if(abs(a[i]) == 1) {
        ans = max(ans, a[i]);
        found = true;
      }
      for(int j = i - 1; j >= 1; j--) {
        if(__gcd(abs(a[j]), abs(a[i])) == 1) {
          found = true;
          ans = max(ans, pref[i] - pref[j - 1]);
        }
      }
      dbg(ans);
    }
    if(found)
      cout << ans << '\n';
    else 
      cout << "NOT FOUND\n";
  }
}

