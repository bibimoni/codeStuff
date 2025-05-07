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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    int comps = 0;
    const vector<int> dir = {-1, 0, 1, 0, -1};
    vector<vector<int>> was(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        if (was[i][j] || a[i][j] == 'x') {
          continue;
        }
        comps += 1;
        queue<pair<int, int>> que;
        que.push({i, j});
        while (que.size()) {
          auto [ux, uy] = que.front();
          que.pop();
          if (was[ux][uy] != 0 || a[ux][uy] == 1) {
            continue;
          }
          was[ux][uy] = comps;
          for (int k = 0; k < 4; k++) {
            int vx = ux + dir[k];
            int vy = uy + dir[k + 1];
            if (vx < 0 || vx > 1 || vy < 0 || vy > n - 1) {
              continue;
            }
            que.push({vx, vy});
          }
        }
      }
    }
    auto findComps = [&] (int i, int j, char t) -> int {
      a[i][j] = t;
      bool ok = true;
      for (int x = max(0ll, j - 1); x <= min(n - 1, j + 1); x++) {
        ok &= a[1 ^ i][x] != 'x';
      }      
      if (ok) {
        return 1;
      }
      if (min(n - 1, j + 1) - max(0ll, j - 1) < 2) {
        return 2;
      }
      if (a[1 ^ i][j - 1] == 'x' && a[1 ^ i][j + 1] == 'x' && a[1 ^ i][j] == '.' && a[i][j - 1] == '.' && a[i][j + 1] == '.') {
        return 3;
      }
      return 2;
    };
    int ans = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 'x') {
          continue;
        }
        int diff = findComps(i, j, 'x');
        a[i][j] = '.';
        set<int> curr;
        for (int i1 = 0; i1 < 2; i1++) {
          for (int x = max(0ll, j - 1); x <= min(n - 1, j + 1); x++) {
            if (a[i1][x] != 'x') {
              curr.insert(was[i1][x]); 
            }
          } 
        }
        diff -= curr.size();
        ans += diff == 3 - comps;        
      }
    }
    cout << ans << '\n';
  }
}


