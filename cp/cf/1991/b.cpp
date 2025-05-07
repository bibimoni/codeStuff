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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
      cin >> b[i];
    }
    vector<int> ans(n);
    ans[0] = b[0];
    for (int i = 1; i < n; i++) {
      if (i < n - 1) {
        ans[i] = b[i - 1] | b[i];
      } else {
        ans[i] = b[n - 2];
      }
    }
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      ok &= ((ans[i] & ans[i + 1]) == b[i]);
    }
    if (!ok) {
      cout << "-1\n";
    } else {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
      }
    }
  }
}


