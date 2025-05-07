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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  int x0, y0, xD, yD;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c; cin >> c;
      if(c == 'A') {x0 = i; y0 = j;}
      if(c == 'B') {xD = i; yD = j;}
      if(c == '#') vis[i][j] = true;
    }
  }
  vector<vector<pair<int, int>>> trace(n, vector<pair<int, int>>(m));
  vector<vector<int>> d(n, vector<int>(m, INF));
  d[x0][y0] = 0;
  set<pair<int, pair<int, int>>> s;
  s.insert({0, {x0, y0}});
  trace[x0][y0] = {-1, -1};
  int dirX[] = {1, 0, 0, -1},
    dirY[] = {0, -1, 1, 0}; //DLRU
  while(!s.empty()) {
    auto [w, p] = *s.begin(); s.erase(s.begin());
    auto [x, y] = p;
    if(vis[x][y]) continue;
    vis[x][y] = true;
    for(int i = 3; i >= 0; i--) {
      int uX = x + dirX[i];
      int uY = y + dirY[i];
      if(uX >= 0 && uY >= 0 && uX < n && uY < m && !vis[uX][uY]) {
        if(d[uX][uY] > 1 + d[x][y]) {
          //dbg(uX, uY, x, y);
          d[uX][uY] = 1 + d[x][y];
          s.insert({d[uX][uY], {uX, uY}});
          trace[uX][uY] = {x, y};
        }
        if(d[uX][uY] == 1 + d[x][y]) {
          auto [pX, pY] = trace[uX][uY];
          if(y < pY || x > pX) trace[uX][uY] = {x, y};
        }
      }
    }
  }
  if(d[xD][yD] == INF) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  cout << d[xD][yD] << '\n';
  vector<char> res;
  while(trace[xD][yD].first != -1 && trace[xD][yD].second != -1) {
    auto [x, y] = trace[xD][yD];
    if(x > xD) res.push_back('U');
    if(x < xD) res.push_back('D');
    if(y > yD) res.push_back('L');
    if(y < yD) res.push_back('R');
    xD = x;
    yD = y;
  }
  reverse(all(res));
  for(char i : res) cout << i;
}
