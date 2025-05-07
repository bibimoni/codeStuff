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
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      cnt[x] += 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += cnt[i] / 2;
    }
    cout << ans << '\n';
  }
}


