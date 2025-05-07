// tn - 1me-limit: 3000
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = accumulate(a.begin(), a.end(), 0ll);
    vector<int> cnt(n + 1, 0);
    auto go = [&] () -> void {
      cnt = vector<int>(n + 1, 0);
      int cur = 0;
      for (int i = 0; i < n; i++) {
        cnt[a[i]] += 1;
        if (cnt[a[i]] > 1 && a[i] > cur) {
          cur = a[i];
        }
        a[i] = cur;
      }
    };
    for (int k = 0; k < 5; k++) {
      go();
      ans += accumulate(a.begin(), a.end(), 0ll);
    }
    go();
    for (int i = 1; i < n; i++) {
      a[i] += a[i - 1];
    }
    ans += accumulate(a.begin(), a.end(), 0ll);
    cout << ans << '\n';    
  }
}


