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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int mx = int(-1e9);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, vector<pair<int, int>>> s;
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (int j = i; j >= 1; j--) {
      cur += a[j];
      s[cur].push_back({j, i});
    }
  }
  vector<pair<int, int>> ans;
  for (auto& [_, segs] : s) {
    int rt = 0;
    vector<pair<int, int>> cur;
    for (auto [l, r] : segs) {
      if (rt < l) {
        cur.push_back({l, r});
        rt = r;
      }
    }
    if (cur.size() > ans.size()) {
      swap(cur, ans);
    }
  }
  cout << ans.size() << '\n';
  for (auto& [l, r] : ans) {
    cout << l << ' ' << r << '\n';
  }
}

