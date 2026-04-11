/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }

    vector<int> pmn(n + 1, n + 1), smx(n + 2);
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
      pmn[i] = min(pmn[i - 1], p[i]);
    }
    for (int i = n; i >= 1; i--) {
      smx[i] = max(smx[i + 1], p[i]);
    }
    bool ok = true;
    set<int, greater<int>> st{p.begin() + 2, p.end()};
    set<int> st2{p[1]};
    auto cur = st2.begin();
    for (int i = 1; i + 1 <= n; i++) {
      ok &= pmn[i] < smx[i + 1];
      edges.push_back({*cur, *st.begin()});
      int old = *st.begin();
      st2.insert(p[i + 1]);
      st.erase(p[i + 1]);
      dbg(st, st2);
      if (old == *st.begin()) {
        cur++;
        if (cur == st2.end()) {
          cur = st2.find(p[i + 1]);
        }
      } else {
        cur = st2.begin();
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
    if (ok) {
      for (auto [u, v] : edges) {
        cout << u << ' ' << v << '\n';
      }
    }
  }
}
