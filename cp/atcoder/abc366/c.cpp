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
  int q;
  cin >> q;
  multiset<int> st;
  int ans = 0;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      if (st.find(x) == st.end()) {
        ans += 1;
      }
      st.insert(x);
    } else if (t == 2) {
      int x;
      cin >> x;
      st.erase(st.find(x));
      if (st.find(x) == st.end()) {
        ans -= 1;
      }
    } else {
      cout << ans << '\n';
    }
  }
}


