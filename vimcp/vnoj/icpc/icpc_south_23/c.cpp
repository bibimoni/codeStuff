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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

vector<pair<int, int>> qX, qY, qZ;
map<int, int> cntX, cntY, cntZ;
map<pair<int, int>, int> cntXY;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k; cin >> n >> k;
  for(int x, y, z, i = 0; i < k; i++) {
    cin >> x >> y >> z;
    if(x == 0) qX.pb({y, z});
    if(y == 0) qY.pb({x, z});
    if(z == 0) qZ.pb({x, y});
  }
  int ans = 0;
  for(auto [y, z] : qX) {
    cntZ[z]++;
    cntY[y]++;
    ans += n;
  }
  for(auto [x, z] : qY) {
    ans += n - cntZ[z];
    cntX[x]++;
  }
  for(auto [y, zX] : qX) {
    for(auto [x, zY] : qY) {
      if(zX == zY) cntXY[{x, y}]++;
    }
  }
  for(auto [x, y] : qZ) {
    ans += n - cntY[y] - cntX[x] + cntXY[{x, y}];
  }
  cout << ans;
}



