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
    if (is_sorted(a.begin() + 1, a.end())) {
      cout << "0\n";
      continue;
    }
    int ans = 0, curr = 0, add = 0;
    for (int i = 1; i <= n; i++) {
      ans += max(curr - a[i], 0ll);
      add = max(add, curr - a[i]);
      curr = max(curr, a[i]);
    }
    ans += add;
    cout << ans << '\n';
  }
}


