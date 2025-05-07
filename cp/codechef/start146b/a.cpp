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
    int n = 16;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0ll);
    sort(p.begin(), p.end(), [&] (int i, int j) {
      return a[i] < a[j];
    });
    vector<int> wins = {0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4};
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[p[i]] = wins[i];
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
}


