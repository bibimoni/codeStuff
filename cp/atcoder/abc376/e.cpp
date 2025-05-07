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
    int k, n;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    sort(p.begin() + 1, p.end(), [&] (int i, int j) {
      return a[i] < a[j];
    });
    multiset<int> st;
    int sum = 0;
    for (int id = 1; id <= k; id++) {
      int i = p[id];
      sum += b[i];
      st.insert(b[i]);
    }
    int ans = sum * a[p[k]];
    for (int id = k + 1; id <= n; id++) {
      int i = p[id];
      auto mx = *st.rbegin();
      st.erase(st.find(mx));
      sum -= mx;
      st.insert(b[i]);
      sum += b[i];
      ans = min(ans, sum * a[i]);
      st.erase(st.find(b[i]));
      sum -= b[i];
      st.insert(mx);
      sum += mx;
      ////
      st.insert(b[i]);
      sum += b[i];
      mx = *st.rbegin();
      sum -= mx;
      st.erase(st.find(mx));
      if (st.find(b[i]) != st.end()) {
        ans = min(ans, sum * a[i]);
      }
    }
    cout << ans << '\n';
  }
}


