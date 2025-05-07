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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    multiset<int> st(a.begin(), a.end());
    int ans = 0;
    while (true) {
      int f = *st.begin(), s = *next(st.begin());
      int t = *st.rbegin();
      if (f + s <= t) {
        st.erase(st.begin());
        st.insert(t);
        ans += 1;
      } else {
        break;
      }
    }
    cout << ans << '\n';
  }
}


