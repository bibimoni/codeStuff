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
    int n, k;
    cin >> n >> k;
    vector<int> cnt(k + 1, 0);
    for (int i = 0; i < k; i++) {
      int b, c;
      cin >> b >> c;
      cnt[b] += c;
    }
    sort(cnt.begin() + 1, cnt.end(), greater<int>());
    int ans = 0;
    for (int i = 1; i <= min(n, k); i++) {
      ans += cnt[i];
    }
    cout << ans << '\n';
  }
}


