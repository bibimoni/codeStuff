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
  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  int cntA = 0;
  vector<pair<int, int>> setA;
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if(a[i][j] == '#') {
        cntA++;
        setA.push_back({i, j});
      }
     } 
  int ans = n * m;
  auto canUse = [&] (pair<int, int> curr, vector<pair<int, int>> remove) {
    auto [xt, yt] = curr;
    if(xt < 1 || yt < 1 || xt > n || yt > m) {
      return false;
    }
    if(a[xt][yt] == '.') {
      return false;
    }
    for(auto [x, y] : remove) {
      if(xt == x && yt == y) {
        return false;
      }
    }
    return true;
  };
  auto checkPossible = [&] (vector<pair<int, int>> remove) {
    //find start position
    bool vis[n + 1][m + 1];
    pair<int, int> start({-1, -1});
    for(int i = 1; i <= n; i++) {
      if(start != pair<int, int>({-1, -1}))
        break;
      for(int j = 1; j <= m; j++) {
        if(canUse({i, j}, remove)) {
          start = {i, j};
          break;
        }
      }
    }
    for(int i = 1; i <= n; i++) 
      for(int j = 1; j <= m; j++)
        vis[i][j] = false;
    queue<pair<int, int>> q;
    if(start == pair<int, int>({-1, -1}))
      return false;
    q.push(start);
    int cnt = 1;
    vis[start.first][start.second] = true;
    int d[] = {-1, 0, 1, 0, -1};
    while(q.size()) {
      auto [ux, uy] = q.front();
      q.pop();
      for(int i = 0; i < 4; i++) {
        int vx = ux + d[i];
        int vy = uy + d[i + 1];
        if(!canUse({vx, vy}, remove) || vis[vx][vy])
          continue;
        q.push({vx, vy});
        vis[vx][vy] = true;
        cnt++;
      }
    }
    return (bool) (cnt != (cntA - (int) remove.size()) && cntA - (int) remove.size());
  };
  //answer is 1
  for(auto [x, y] : setA) {
    if(checkPossible({{x, y}})) {
      ans = 1;
      break;
    }
  }
  if(cntA <= 2) {
    cout << -1;
  }
  else if(ans == 1) {
    cout << 1;
  }
  else if(cntA > 2 && ans != 1) {
    cout << 2;
  }
}

