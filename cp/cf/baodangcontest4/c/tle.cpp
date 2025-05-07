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
    multiset<int, greater<int>> st(a.begin(), a.end());
    bool ok = true;
    while (st.size()) {
      while (st.size() && *st.rbegin() == 0) {
        st.erase(prev(st.end()));
      }
      if (st.size() == 0) {
        break;
      }
      int u = *st.begin();
      if (st.size() == 1) {
        ok &= (u == 0);
        break;
      }
      st.erase(st.find(u));
      vector<int> np;
      for (int i : st) {
        np.push_back(i - (u > 0 ? 1 : 0));
        if (np.back() < 0) {
          ok = false;
          break;
        }
        u -= 1;
      }
      if (!ok || u > 0) {
        ok = false;
        break;
      }
      st = multiset<int, greater<int>>(np.begin(), np.end());
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}

