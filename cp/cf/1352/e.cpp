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
    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i];
    }
    auto find = [&] (int e) {
      for(int i = 1; i <= n - 1; i++) {
        int l = i + 1, r = n;
        while(l <= r) {
          int mid = (l + r) >> 1;
          if(pref[mid] - pref[i - 1] > e) {
            r = mid - 1;
          }
          else if(pref[mid] - pref[i - 1] < e) {
            l = mid + 1;
          }
          else {
            return true;
          }
        }
      }
      return false;
    };
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += find(a[i]);
    }
    cout << ans << '\n';
  }
}


