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

int dist(int x, int y, int n) {
  return abs(x - y) > abs(x + n - y) ? abs(x + n - y) : abs(x - y);
}

bool cmp(int x, int y, int z, int t, int n) {
  bool a = abs(x - z) > abs(x + n - z) ? 
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    for (int j = 0; j < a.size(); j++) {
      if (
        (dist(a[j].first, x, n) == dist(a[j].second, y, n) 
        || dist(a[j].first, y, n) == dist(a[j].second, x, n)
        )
        && x != a[j].first && y != a[j].second
        && x != a[j].second && y != a[j].first) {
        dbg(x, y, a[j]);
      }
      ans += dist(a[j].first, x, n) != dist(a[j].second, y, n);
    }
    a.push_back({x, y});
  }
  cout << ans << '\n';
}


