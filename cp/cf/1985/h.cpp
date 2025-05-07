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
#define sz(_x) (_x).size()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    const vector<int> d = {-1, 0, 1, 0, -1};
    vector<vector<int>> was(n, vector<int>(m, 0)), b(n, vector<int>(m, 0));
    vector<int> fr(n, 0), fc(m, 0);
    auto bfs = [&] (int x, int y) -> void {
      queue<pair<int, int>> q;
      q.push({x, y});
      int ret = 0;
      int minR = n - 1, maxR = 0, minC = m - 1, maxC = 0;
      while(q.size()) {
        auto [ux, uy] = q.front();
        q.pop();
        if(was[ux][uy])
          continue;
        minR = min(max(ux - 1, 0ll), minR);
        maxR = max(min(ux + 1, n - 1ll), maxR);
        minC = min(max(uy - 1, 0ll), minC);
        maxC = max(min(uy + 1, m - 1ll), maxC);
        ret++;
        was[ux][uy] = 1;
        for(int i = 0; i < 4; i++) {
          int vx = ux + d[i], vy = uy + d[i + 1];
          if(vx < 0 || vy < 0 || vx >= n || vy >= m)
            continue;
          if(a[vx][vy] == '#')
            q.push({vx, vy});
        }
      }
      for(int i = minR; i <= maxR; i++)
        fr[i] += ret;
      for(int i = minC; i <= maxC; i++)
        fc[i] += ret;
      for(int i = minR; i <= maxR; i++) 
        for(int j = minC; j <= maxC; j++)
          b[i][j] += ret;
    };
    for(int i = 0; i < n; i++) 
      for(int j = 0; j < m; j++) 
        if(a[i][j] == '#' && !was[i][j]) 
          bfs(i, j);
    vector<int> nonR(n, 0);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        nonR[i] += a[i][j] == '.';
    vector<int> nonC(m, 0);
    for(int j = 0; j < m; j++)
      for(int i = 0; i < n; i++)
        nonC[j] += a[i][j] == '.';
    int ans = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        ans = max(ans, fr[i] + fc[j] - b[i][j] + nonR[i] + nonC[j] - (int) (a[i][j] == '.'));
    cout << ans << '\n';  
  }
}

