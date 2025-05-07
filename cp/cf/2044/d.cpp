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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> cnt(n + 1, 0);
    int cur_slot = 1;
    int mx = 1;
    vector<int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++) {
      while (cnt[a[i]] < mx) {
        ans[cur_slot] = a[i];
        cur_slot += 1;
        cnt[a[i]] += 1;
      }
    }
    for (int i = 1; cur_slot <= n && i <= n; i++) {
      if (cnt[i] == 0) {
        ans[cur_slot] = i;
        cur_slot += 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
}


