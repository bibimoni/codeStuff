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
    vector<int> a(n + 1);
    map<int, vector<int>> dp;
    set<pair<int, int>> states;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      dp[a[i] - 1 + i].push_back(i - 1);
      if (a[i] - 1 + i == n) {
        states.insert({a[i] - 1 + i, i - 1});
      }
    }
    // dbg(dp);
    int ans = n;
    while (states.size()) {
      auto [len, ext] = *states.begin();
      dbg(states);
      states.erase(states.begin());
      ans = max(ans, len + ext);
      if (ext != 0) {
        for (int nxt : dp[len + ext]) {
          states.insert({len + ext, nxt});
        }
      }
    }
    cout << ans << '\n';
  }
}

