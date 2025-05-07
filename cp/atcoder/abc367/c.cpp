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
  int n, k;
  cin >> n >> k;
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    cin >> r[i];
  }
  auto dfs = [&] (auto &&self, int d, vector<int> &cur) -> void {
    if (d == n) {
      if (accumulate(cur.begin(), cur.end(), 0ll) % k == 0) {
        for (int i : cur) {
          cout << i << ' ';
        }
        cout << '\n';
      }
      return;
    }
    for (int j = 1; j <= r[d]; j++) {
      cur.push_back(j);
      self(self, d + 1, cur);
      cur.pop_back();
    }
  };
  vector<int> tmp;
  dfs(dfs, 0, tmp);
}


