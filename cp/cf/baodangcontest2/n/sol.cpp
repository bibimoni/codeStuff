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

const int INF = (int) 2e9;

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
    vector<int> pref(n + 1, 0), suf(n + 2, INF);
    for(int i = n; i >= 1; i--) {
      suf[i] = min(suf[i + 1], a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      pref[i] = max(pref[i - 1], a[i]);
      ans += (pref[i - 1] <= a[i] && a[i] < suf[i + 1]);
    }
    cout << ans << '\n';
  }
}

