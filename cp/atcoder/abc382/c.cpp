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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<pair<int, int>> st;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    st.insert({x, i});
  }
  vector<int> ans(m, -1);
  for (int i = 0; i < n; i++) {
    auto it = st.lower_bound({a[i], -1});
    if (it == st.end()) {
      continue;
    }
    vector<pair<int, int>> rem;
    for (auto itr = it; itr != st.end(); itr++) {
      rem.push_back(*itr);
      auto [_, id] = *itr;
      ans[id] = i + 1;
    }
    for (auto p : rem) {
      st.erase(st.find(p));
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}


