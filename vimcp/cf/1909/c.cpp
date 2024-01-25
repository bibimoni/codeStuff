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
    int n; cin >> n;
    vector<int> r(n), c(n);
    multiset<int> l;
    for(int x, i = 0; i < n; i++) {
      cin >> x;
      l.insert(x);
    }
    for(int i = 0, x; i < n; i++) {
      cin >> r[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> c[i];
    }
    sort(r.begin(), r.end());
    vector<int> sub(n);
    for(int i = 0; i < n; i++) {
      sub[i] = r[i] - *prev(l.lower_bound(r[i]));
      l.erase(*prev(l.lower_bound(r[i])));
    }
    sort(sub.begin(), sub.end());
    sort(c.begin(), c.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++) {
      ans += sub[i] * c[i];
    }
    cout << ans << '\n';
  }
}