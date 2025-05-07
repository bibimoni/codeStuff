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
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, char>> a(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    a[i] = {x, y, c};
  }
  sort(a.begin(), a.end());
  int mn = n + 1;
  bool ok = true;
  for (auto [x, y, c] : a) {
    if (c == 'W') {
      mn = min(y, mn);
    } else {
      ok &= y < mn;
    }
  }
  cout << (ok ? "Yes\n" : "No\n");
}



