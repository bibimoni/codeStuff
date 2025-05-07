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
  vector<vector<int>> cands(n, vector<int>(m));
  vector<vector<pair<int, int>>> ranges(m);
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < m; j++) {
      cin >> cands[i][j];
      ranges[j].push_back({cur, cur + cands[i][j] - 1});
      cur += cands[i][j];
    }
  }
  vector<int> ans(m);
  for (int j = 0; j < m; j++) {
    vector<pair<int, int>> s;
    for (auto [l, r] : ranges[j]) {
      s.push_back({l, 1});
      s.push_back({r + 1, -1});
    }
    sort(s.begin(), s.end());
    int cur = 0;
    for (auto [_, v] : s) {
      cur += v;
      ans[j] = max(ans[j], cur);
    }
  }
  for (int j = 0; j < m; j++) {
    cout << ans[j] << ' ';
  }
}

