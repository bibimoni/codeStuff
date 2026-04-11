/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <new>
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
    int mxk = 0;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      mxk = max(mxk, k);
      for (int j = 0; j < k; j++) {
        int x;
        cin >> x;
        a[i].push_back(x);
      }
    }

    vector<vector<pair<int, int>>> cols(mxk);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < int(a[i].size()); j++) {
        cols[j].push_back({a[i][j], i});
      }
    }

    vector<int> ids(n, 1e9);
    for (int j = mxk - 1; j >= 0; j--) {
      sort(cols[j].begin(), cols[j].end(), [&](auto u, auto v) {
        if (u.first != v.first) {
          return u.first < v.first;
        }
        return ids[u.second] < ids[v.second];
      });

      for (int i = 0; i < (int)cols[j].size(); i++) {
        ids[cols[j][i].second] = i;
      }
    }

    vector<int> ans;
    int cur = 0;
    while ((int)cols.size() > cur) {
      assert(cols[cur].size() > 0);
      auto [val, id] = cols[cur][0];
      for (int i = cur; i < int(a[id].size()); i++) {
        ans.push_back(a[id][i]);
      }
      cur = a[id].size();
    }

    for (int i = 0; i < int(ans.size()); i++) {
      cout << ans[i] << " \n"[i == int(ans.size()) - 1];
    }
  }
}
