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
  int n;
  cin >> n;
  map<pair<int, int>, int> cnt;
  vector<array<int, 3>> a(n);
  for(int i = 0; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    a[i] = {{x, y, w}};
    cnt[{x, y}] += w;
  }
  sort(a.begin(), a.end(), [&] (array<int, 3> i, array<int, 3> j) {
    if(i[0] == j[0])
      return i[1] < j[1];
    return i[0] < j[0];
  });
  auto get = [&] (int u, int v) -> int {
    int dX[] = {-1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2};
    int dY[] = {-1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, 0};
    int ret = 0;
    for(int i = 0; i < 12; i++) {
      ret += cnt[{u + dX[i], v + dY[i]}];
    }
    return ret;
  };
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int u = a[i][0], v = a[i][1];
    if(n <= 1e3) {
      int dX[] = {1, 1, 1, 0, -1, -2, -1, 0};
      int dY[] = {1, 0, -1, -2, -1, 0, 1, 2};
      for(int j = 0; j < 8; j++) {
        ans = max(ans, get(u + dX[j], v + dY[j]));
      }
    }
    else {
      for(int x = a[i][0] - 1; x <= a[i][0] + 1; x++)
        for(int y = a[i][1] - 1; y <= a[i][1] + 1; y++)
          if(x == a[i][0] || y == a[i][1])
            ans = max(ans, get(x, y));
    }
  }
  cout << ans;
}


