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

const int N = 10, M = 5050;
int a[N][M];
int n, m;
const int INF = 1e9;
int dir[] = {-1, 0, 1, 0, -1};
void sub_13() {
  auto dijkstra = [&] (int posx, int posy) -> vector<vector<int>> {
    vector<vector<int>> d(n + 1, vector<int>(m + 1, INF));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({a[posx][posy], posx, posy});
    d[posx][posy] = a[posx][posy];
    while (pq.size()) {
      auto p = pq.top();
      pq.pop();
      int w = p[0], ux = p[1], uy = p[2];
      if (d[ux][uy] != w) {
        continue;
      }
      for (int k = 0; k < 4; k++) {
        int vx = ux + dir[k];
        int vy = uy + dir[k + 1];
        if (vx < 1 || vy < 1 || vx > n || vy > m) {
          continue;
        }
        if (d[vx][vy] > d[ux][uy] + a[vx][vy]) {
          d[vx][vy] = d[ux][uy] + a[vx][vy];
          pq.push({d[vx][vy], vx, vy});
        }
      }
    }
    return d;
  };
  vector<vector<int>> di[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      di[i][j] = dijkstra(i, j);
    }
  }
  // dbg(dijkstra(1, 1));
  int q;
  cin >> q;
  while (q--) {
    int xs, ys, xe, ye;
    cin >> xs >> ys >> xe >> ye;
    cout << di[xs][ys][xe][ye] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("MINPATH.inp", "r", stdin);
  // freopen("MINPATH.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  sub_13();
}


