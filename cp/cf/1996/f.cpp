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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    auto calc = [&] (int idx, int step) -> int {
      step -= 1;
      return (step + 1) * a[idx] - ((step + 1) * step) / 2 * b[idx];
    };
    vector<pair<int, int>> os(n + 1);
    vector<int> used(n + 1, 0);
    multiset<array<int, 3>, greater<array<int, 3>>> st;
    // potential score, idx, number of operations
    for (int i = 1; i <= n; i++) {
      int step = a[i] / b[i] + (a[i] % b[i] != 0);
      int score = calc(i, step);
      os[i] = {score, step};
      used[i] = step;
      st.insert({score, step, i});
    }
    dbg(st);
    int cur = k;
    while (st.size() && cur > 0) {
      auto p = *st.begin();
      int score = p[0], idx = p[2], step = p[1];
      st.erase(st.begin());
      int use = min(cur, step);
      dbg(use, idx);
      cur -= use;
      used[idx] -= use;
      if (used[idx] > 0) {
        auto [oscore, ostep] = os[idx];
        int usedStep = ostep - used[idx];
        st.insert({oscore - calc(idx, usedStep), used[idx], idx});
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      auto [oscore, ostep] = os[i];
      int usedStep = ostep - used[i];
      ans += calc(i, usedStep);
    }
    cout << ans << '\n';
  }
}


  