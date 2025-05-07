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
    int m, x;
    cin >> m >> x;
    multiset<int, greater<int>> st;
    vector<int> c(m);
    int cost = 0;
    for(int i = 0; i < m; i++) {
      cin >> c[i];
      st.insert(c[i]);
      cost += c[i];
      while(cost > i * x) {
        cost -= (*st.begin());
        st.erase(st.begin());
      }
    }
    cout << st.size() << '\n';
  }
}


