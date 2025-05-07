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
  vector<int> save(3 * n + 5, 0);
  int ans = 0;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    ans += save[(x + y) % n];
    save[(x + y) % n] += 1;
  }
  dbg(ans);
  ans = ((m * (m - 1)) / 2) - ans;
  cout << ans << '\n';
}


