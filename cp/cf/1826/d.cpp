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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    vector<int> pref(n + 1, -INF), suf(n + 2, -INF);
    for(int i = 1; i <= n; i++) {
      pref[i] = max(b[i] + i, pref[i - 1]);
    }
    for(int i = n; i >= 1; i--) {
      suf[i] = max(b[i] - i, suf[i + 1]);
    }
    int ans = 0;
    for(int i = 2; i < n; i++) {
      ans = max(ans, b[i] + pref[i - 1] + suf[i + 1]);
    }
    cout << ans << '\n';
  }
}

