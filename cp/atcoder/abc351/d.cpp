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
  int h, w;
  cin >> h >> w;
  vector<string> a(h + 1);
  for(int i = 1; i <= h; i++) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  auto doIt = [&] (int i, int j) -> void{
    for(int it = i - 1; it <= i + 1; it++) {
      for(int jt = j - 1; jt <= j + 1; jt++) {
        if(it >= 1 && it <= h && jt >= 1 && jt <= w) {
          if(a[it][jt] == '.' && (it == i || jt == j))
            a[it][jt] = '@';
        }
      }
    }
  };
  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      if(a[i][j] == '#') {
        doIt(i, j);      
      }
    }
  }
  vector<vector<int>> was(h + 1, vector<int>(w + 1, 0));
  auto bfs = [&] (int i, int j) -> int {
    queue<pair<int, int>> q;
    set<pair<int, int>> cant;
    int ret = 0;
    q.push({i, j});
    while(q.size()) {
      auto [ux, uy] = q.front();
      q.pop();
      if(was[ux][uy])
        continue;
      ret++;
      was[ux][uy] = 1;
      int d[] = {-1, 0, 1, 0, -1};
      for(int i = 0; i < 4; i++) {
        int vx = ux + d[i], vy = uy + d[i + 1];
        if(vx >= 1 && vy >= 1 && vx <= h && vy <= w) {
          if(a[vx][vy] == '.') {
            q.push({vx, vy});
          }
          else if(a[vx][vy] == '@' && cant.find({vx, vy}) == cant.end()) {
            ret++;
            cant.insert({vx, vy});
          }
        }
      }
    }
    return ret;
  };
  int ans = 1;
  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      if(a[i][j] == '.' && !was[i][j]) {
        ans = max(ans, bfs(i, j));
        was[i][j] = 1;
      }
    }
  }
  cout << ans;
}


