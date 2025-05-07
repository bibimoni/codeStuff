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
    int n, m, L;
    cin >> n >> m >> L;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    vector<pair<int, int>> p(m + 1);
    for (int i = 1; i <= m; i++) {
      cin >> p[i].first >> p[i].second;
    }
    int ans = 0;
    int cur = 1;
    bool ok = true;
    int id = 1;
    multiset<int> seg;
    for (int i = 1; i <= n; i++) {
      auto [l, r] = a[i];
      while (id <= m) {
        auto [x, k] = p[id];
        if (x >= l) {
          break;
        }
        seg.insert(k);
        id += 1;
      }
      if (cur > r - l + 1) {
        continue;
      } else {
        bool can = false;
        while (seg.size()) {
          cur += *prev(seg.end());
          seg.erase(prev(seg.end()));
          ans += 1;
          if (cur > r - l + 1) {
            can = true;
            break;
          }
        }
        if (!can) {
          ok = false;
          break;
        }
      }
    } 
    cout << (ok ? ans : -1) << '\n';
  }
}
