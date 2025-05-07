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
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 1;
    set<int> st;
    for (int i = 1; i <= n; i++) {
      if (x % a[i] != 0) {
        continue;
      }
      if (st.find(x / a[i]) != st.end()) {
        ans++;
        st.clear();
      } else {
        vector<int> add;
        for (int num : st) {
          add.push_back(a[i] * num);
        }
        for (int num : add) {
          if (x % num == 0) {
            st.insert(num);
          }
        }
      }
      st.insert(a[i]);
    }
    cout << ans << '\n';
  }
}