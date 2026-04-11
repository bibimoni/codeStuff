#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minSplitMerge(vector<int> &a, vector<int> &b) {
    const int lim = 1;
    int n = (int)a.size();
    map<vector<int>, int> vis1;
    map<vector<int>, int> vis2;
    auto dfs = [&](auto &&self, vector<int> cur, int cnt,
                   map<vector<int>, int> &vis) {
      if (vis.count(cur))
        vis[cur] = min(vis[cur], cnt);
      else
        vis[cur] = cnt;
      return;
      if (cnt > lim) {
        return;
      }
      for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
          vector<int> sub{cur.begin() + l, cur.begin() + r + 1};
          vector<int> rem;
          rem.insert(rem.end(), cur.begin(), cur.begin() + l);
          rem.insert(rem.end(), cur.begin() + r + 1, cur.end());
          for (int k = 0; k <= (int)rem.size(); k++) {
            vector<int> nxt = rem;
            nxt.insert(nxt.begin() + k, sub.begin(), sub.end());
            self(self, nxt, cnt + 1, vis);
          }
        }
      }
    };

    int ans = 6;
    dfs(dfs, a, 0, vis1);
    dfs(dfs, b, 0, vis2);
    for (auto x : vis1) {
      for (auto y : vis2) {
        if (x.first == y.first) {
          ans = min(ans, x.second + y.second);
        }
      }
    }

    return ans;
  }
};
