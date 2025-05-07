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
    int n, q;
    cin >> n >> q;
    int c[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    int pref[n + 1]; pref[0] = 0;
    int sum[n + 1]; sum[0] = 0;
    for(int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (c[i] == 1);
      sum[i] = sum[i - 1] + c[i];
    }
    while(q--) {
      int l, r;
      cin >> l >> r;
      cout << (((pref[r] - pref[l - 1] <= sum[r] - sum[l - 1] - (r - l + 1)) && l != r) ? "YES\n" : "NO\n");
    }
  }
}


