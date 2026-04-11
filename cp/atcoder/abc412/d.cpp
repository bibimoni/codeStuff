/**
 * Author: distiled
 */
#include <algorithm>
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
  int n, m;
  cin >> n >> m;

  map<pair<int, int>, int> mp;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    mp[{u, v}] = 1;
    mp[{v, u}] = 1;
  }

  const int INF = 1e9;
  int ans = INF;
  auto dfs = [&](auto &&self, vector<int> &gr, int id) -> void {
    dbg(gr);
    if (id + 1 < n) {
      gr[id + 1] = gr[id] + 1;
      self(self, gr, id + 1);
      gr[id + 1] = gr[id];
      self(self, gr, id + 1);
    } else {
      vector<int> ord(n);
      iota(ord.begin(), ord.end(), 0);
      // dbg(gr);
      do {
        int keep = 0;
        int add = 0;
        bool ok = true;
        vector<int> ll{0};
        set<pair<int, int>> st;
        for (int i = 1; i < n; i++) {
          if (gr[i] != gr[i - 1]) {
            if (ll.size() < 3) {
              ok = false;
              break;
            }
            for (int j = 0; j < int(ll.size()); j++) {
              int u = ord[ll[j]];
              int v = ord[ll[(j + 1) % int(ll.size())]];
              if (mp[{u, v}]) {
                keep += 1;
              } else {
                add += 1;
              }
            }

            ll.clear();
            ll.push_back(i);
          } else {
            ll.push_back(i);
          }
        }
        if (ll.size() < 3 || !ok) {
          continue;
        }
        for (int j = 0; j < int(ll.size()); j++) {
          int u = ord[ll[j]];
          int v = ord[ll[(j + 1) % int(ll.size())]];
          if (mp[{u, v}]) {
            keep += 1;
          } else {
            add += 1;
          }
        }

        // if (gr == vector<int>(n, 0)) {
        //   // dbg(ord, keep, add, add + m - keep);
        // }
        ans = min(ans, add + m - keep);
        // if (add + m - keep == 1) {
        //   dbg(ord, ll);
        // }
      } while (next_permutation(ord.begin(), ord.end()));
    }
  };

  vector<int> gr(n, 0);
  dfs(dfs, gr, 0);

  cout << ans << '\n';
}
