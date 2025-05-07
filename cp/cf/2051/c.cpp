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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), int(1));
    set<int> st(p.begin(), p.end());
    vector<int> q(k);
    for (int i = 0; i < k; i++) {
      cin >> q[i];
      st.erase(q[i]);
    }
    for (int i = 0; i < m; i++) {
      bool has = st.find(a[i]) != st.end();
      if (has) {
        st.erase(a[i]);
      }
      cout << (st.size() == 0);
      if (has) {
        st.insert(a[i]);
      }
    }
    cout << '\n';
  }
}


