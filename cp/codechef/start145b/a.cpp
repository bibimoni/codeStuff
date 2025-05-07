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
    set<int> st;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] != 0) {
        st.insert(a[i]);
      }
    }
    cout << (int(st.size()) > 1 ? "NO\n" : "YES\n");
  }
}


