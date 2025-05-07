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
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }
    multiset<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] > 0)
        st.insert({cnt[i], i});
    }
    vector<int> cnt_a(n + 1);
    bool a_turn = true;
    while (st.size()) {
      auto [u, c] = *st.begin();
      st.erase(st.begin());
      if (u > 0) {
        if (a_turn) {
          cnt_a[c] += 1;
        }
        u -= 1;
      }
      if (u > 0) {
        st.insert({u, c});
      }
      a_turn = !a_turn;
    } 
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += int(cnt_a[i] > 0) + int(cnt[i] > 0 && cnt[i] == cnt_a[i]);
    }
    cout << ans << '\n';
  }
}


