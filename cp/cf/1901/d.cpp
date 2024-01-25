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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int ans = INF, a[n + 1], pref[n + 1], suf[n + 2];
  suf[n + 1] = pref[0] = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  //make sure that pref[i] has enough power to kill all monster
  //from n -> 
  for(int i = 1; i <= n; i++) {
    pref[i] = max(pref[i - 1], n - i + a[i]);
  }
  for(int i = n; i >= 1; i--) {
    suf[i] = max(suf[i + 1], i - 1 + a[i]);
  }
  for(int i = 1; i <= n; i++) {
    ans = min(ans, max({a[i], pref[i - 1], suf[i + 1]}));
  }
  cout << ans;
}


 