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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<string> a(3);
    cin >> a[1] >> a[2];
    a[1] = " " + a[1];
    a[2] = " " + a[2];
    vector<vector<int>> vis(3, vector<int>(n + 1, 0));
    queue<pair<int, int>> q;
    q.push({1, 1});
    auto valid = [&] (int x, int y) -> bool {
      return x >= 1 && y >= 1 && x <= 2 && y <= n;
    };
    int dir[] = {-1, 0, 1, 0, -1};
    bool ok = false;
    while(q.size()) {
      auto [ux, uy] = q.front();
      q.pop();
      if(ux == 2 && uy == n) {
        ok = true;
        break;
      }
      if(vis[ux][uy])
        continue;
      vis[ux][uy] = 1;
      for(int i = 0; i < 4; i++) {
        int vx = ux + dir[i];
        int vy = uy + dir[i + 1];
        if(valid(vx, vy)) {
          if(a[vx][vy] == '<') {
            vy--;
          }
          else {
            vy++;
          }
          if(!valid(vx, vy)) 
            continue;
          q.push({vx, vy});
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


