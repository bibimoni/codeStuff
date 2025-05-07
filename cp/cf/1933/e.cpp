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
#define ld             long double
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
    int pref[n + 1]; pref[0] = 0;
    for(int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i];
    }
    auto f = [&] (int l, int r, int u) {
      int d = pref[r] - pref[l - 1];
      return u * d - (d * (d - 1) / 2);
    };
    int q;
    cin >> q;
    while(q--) {
      int l, u;
      cin >> l >> u;
      int r = lower_bound(pref + l + 1, pref + n + 1, u) - pref;
      cout << r << ' ';
    }
    cout << '\n';
  }
}


