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
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p.emplace_back(x + y, x - y);
  }
  sort(p.begin(), p.end());
  const int INF = int(1e9);
  int blx = -INF, brx = INF, bly = -INF, bry = INF;
  array<vector<array<int,4>>, 2> seg;
  for (auto [x, y] : p) {
    int lx = x - d + 1;
    int rx = x + d - 1;
    int ly = y - d + 1;
    int ry = y + d - 1;
    blx = max(blx, lx);
    bly = max(bly, ly);
    brx = min(brx, rx);
    bry = min(bry, ry);
  }
  cout << (bry - bly + 1) * (p[n - 1].first - p[0].first + 1 - p[0].first - p[0].first);
}


