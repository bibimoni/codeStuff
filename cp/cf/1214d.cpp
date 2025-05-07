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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  vector<vector<int>> st(n + 1, vector<int>(m + 1, 0));
  vector<vector<int>> en(n + 1, vector<int>(m + 1, 0));
  auto dfs = [&] (auto &&self, int isStart, vector<int> &d, int ux, int uy, int px = -1, int py = -1) -> void {
    if ((ux != 1 || uy != 1) && (ux != n || uy != m)) {
      if (isStart) {
        if (st[ux][uy] != 0) {
          return;
        }
        st[ux][uy] = 1;
      } else {
        if (en[ux][uy] != 0) {
          return;
        }
        en[ux][uy] = 1;
      }
    }
    for (int i = 0; i < 2; i++) {
      int vx = ux + d[i];
      int vy = uy + d[i + 1];
      if (vx < 1 || vy < 1 || vx > n || vy > m || a[vx][vy] == '#')
        continue;
      if (vy == py && vx == px)
        continue;
      self(self, isStart, d, vx, vy, ux, uy);
    }
  };
  vector<int> dt = {0, 1, 0};
  dfs(dfs, 1, dt, 1, 1);
  vector<int> de = {0, -1, 0};
  dfs(dfs, 0, de, n, m);
  map<int, int> f;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if(st[i][j] == 1 && en[i][j] == 1) {
        f[i + j]++;
        ans = 2;
      }
    }
  }
  for (auto [_, v] : f) {
    ans = min(min(2ll, v), ans);
  }
  cout << ans;
}

