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
  vector<array<int, 4>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, l, p;
    cin >> u >> v >> l >> p;
  }
  // voi moi tplt manh m goi i
  // dp[i][j] : so thoi gian it nhat ma di qua tplt manh i con j nang luong toi
  // 
}

