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
    multiset<int> st;
    st.insert(n);
    int ans = 0;
    while (st.size() < n) {
      int u = *st.rbegin();
      st.erase(st.find(u));
      ans++;
      for (int i = 0; i < k - 1; i++) {
        st.insert(u / k);
      }
      st.insert(u / k + u % k);
    }
    cout << ans << '\n';
  }
}


