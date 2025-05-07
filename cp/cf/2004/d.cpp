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
    int n, q;
    cin >> n >> q;
    vector<string> portal(n + 1);
    map<string, vector<int>> ids;
    for (int i = 1; i <= n; i++) {
      cin >> portal[i];
      ids[portal[i]].push_back(i);
    }
    const int INF = int(1e9);
    while (q--) {
      int x, y;
      cin >> x >> y;
      if (x == y) {
        cout << "0\n";
        continue;
      }
      if (portal[x] == portal[y]) {
        cout << abs(y - x) << '\n';
        continue;
      }
      if (x > y) {
        swap(x, y);
      }
      int ans = INF;
      for (auto &s : mp[portal[x]]) {      
        if (!ids[s].size()) {
          continue;
        }
        if (s == portal[y]) {
          ans = abs(y - x);
          break;
        }
      }
      for (auto &s : mp[portal[x]]) {
        if (ans != INF) {
          break;
        }
        if (s == portal[x]) {
          continue;
        }
        auto it = lower_bound(ids[s].begin(), ids[s].end(), x);
        if (it == ids[s].end()) {
          continue;
        }
        if (*it <= y) {
          ans = abs(y - x);
          break;
        }
        if (s != portal[x]) {
          auto ity = lower_bound(ids[s].begin(), ids[s].end(), y);
          if (ity != ids[s].end()) {
            ans = min(ans, abs((*ity) - x) + abs((*ity) - y));
          } 
          auto itx = upper_bound(ids[s].begin(), ids[s].end(), x);
          if (itx != ids[s].end()) {
            ans = min(ans, abs((*itx) - x) + abs((*itx) - y));
          }
        }
      }
      cout << (ans == INF ? -1 : ans) << '\n';
    }
  }
}


