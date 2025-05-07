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
  vector<vector<int>> ans;
  auto dfs = [&] (auto &&self, int i, vector<int> &cur) -> void {
    if (i == n) {
      ans.push_back(cur);
      return;
    }
    if (cur.size() == 0) {
      for (int val = 1; val + (n - i - 1) * 10 <= m; val++) {
        cur.push_back(val);
        self(self, i + 1, cur);
        cur.pop_back();
      }
    } else {
      for (int val = cur.back() + 10; val + (n - i - 1) * 10 <= m; val++) {
        cur.push_back(val);
        self(self, i + 1, cur);
        cur.pop_back();
      }
    }
  };
  vector<int> tmp;
  dfs(dfs, 0, tmp);
  cout << ans.size() << '\n';
  for (auto p : ans) {
    for (int i = 0; i < (int)p.size(); i++) {
      cout << p[i] << " \n"[i == (int)p.size() - 1];
    }
  }
}


