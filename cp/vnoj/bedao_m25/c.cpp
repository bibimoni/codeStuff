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
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
  }
  int mx = *max_element(c.begin(), c.end()) + 1;
  vector<vector<int>> kara(mx, vector<int>{0});
  vector<int> del(mx, 0);
  for (int i = 0; i < n; i++) {
    kara[c[i]].push_back(a[i]);
    int sz = kara[c[i]].size();
    kara[c[i]][sz - 1] += kara[c[i]][sz - 2];
  }
  int q;
  cin >> q;
  vector<array<int, 3>> que(q);
  int tot_add = 0;
  for (int i = 0; i < q; i++) {
    cin >> que[i][0] >> que[i][1] >> que[i][2];
    if (que[i][0] == 1) {
      tot_add += que[i][2];
      del[que[i][1]] += que[i][2];
    }
  }
  reverse(que.begin(), que.end());
  vector<int> ans;
  for (const auto p : que) {
    int opt = p[0], col = p[1];
    if (opt == 1) {
      int x = p[2];
      del[col] -= x;
      tot_add -= x;
    } else if (opt == 2) {
      int y = p[2];
      int lo = 1, hi = kara[col].size() - 1, ret = 0;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int val = kara[col][mid] + (tot_add - del[col]) * mid;
        if (val <= y) {
          ret = mid;
          lo = mid + 1; 
        } else {
          hi = mid - 1;
        }
      }
      ans.push_back(ret);
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans) {
    cout << i << '\n';
  }
} 


