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
#define all(x)         x.begin(), x.end()

int n, m, h; 
const int N = (int ) 1e6 + 5, INF = (int) 1e9;
int dir[] = {-1, 0, 1, 0, -1};
vector<pair<int, int>> pos[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m >> h;
  int a[n + 1][m + 1];
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) {
      cin >> a[i][j];
      // a[i][j] co the tham u v neu u * v == a[i][j]]
      pos[i * j].push_back({i, j});
      dbg(i, j, i * j, pos[i * j]);
    }
  while(h--) {
    int p0, q0, r, s; cin >> p0 >> q0 >> r >> s;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
    vector<vector<int>> d(n + 1, vector<int>(m + 1, INF));
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    d[p0][q0] = 0;
    q.push({0, p0, q0});
    while(!q.empty()) {
      auto [w, x, y] = q.top(); q.pop();
      if(vis[x][y]) continue;
      vis[x][y] = true;
      for(int i = 0; i < 4; i++) {
        int vX = x + dir[i];
        int vY = y + dir[i + 1];
        if(vX >= 1 && vY >= 1 && vX <= n && vY <= m) {
          if(d[vX][vY] > 1 + w) {
            d[vX][vY] = 1 + w;
            q.push({d[vX][vY], vX, vY});
          }
        }
      }
      for(int i = 0; i < pos[a[x][y]].size(); i++) {
        auto [x1, y1] = pos[a[x][y]][i];
        if(d[x1][y1] > 3 + d[x][y]) {
          d[x1][y1] = 3 + d[x][y];
          q.push({d[x1][y1], x1, y1});
        }
      }
    }
    cout << d[r][s] << '\n';
  }
}


