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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = (s[i] == '1' ? 1 : -1);
    }
    vector<int> suf(n, 0);
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = suf[i + 1] + a[i + 1];
    }
    dbg(suf);
    sort(suf.begin(), suf.end(), greater<int>());
    dbg(suf);
    int cur = 0, ans = -1;
    for (int i = 0; i < n - 1; i++) {
      cur += suf[i];
      if (cur >= k) {
        ans = i + 2;
        break;
      }
    }
    cout << ans << '\n';
  }
}


