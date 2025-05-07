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
  int growth = 0;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      st.insert(growth);
    } else if (type == 2) {
      int t;
      cin >> t;
      growth += t;
    } else {
      int h;
      cin >> h;
      auto it = st.upper_bound(growth - h);
      if (it != st.begin()) {
        it--;
        int ans = 0;
        while (true) {
          ans += 1;
          if (it == st.begin()) {
            break;
          } 
          it--;
        }
        cout << ans << '\n';
        while (ans--) {
          st.erase(st.begin());
        }
      } else {
        cout << "0\n";
      }
    }
  }
}


