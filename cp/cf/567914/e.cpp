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

const int MOD = (int) 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("random.inp", "r", stdin);
  // freopen("random.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<map<int, int>> dp(n + 1);
  auto memo = [&] (auto &&self, int cur, int i) -> int {
    if (i == n) {
      return cur == 1;
    }
    if (dp[i].count(cur)) {
      return dp[i][cur];
    }
    // dbg(i, cur);
    int ans = 0;
    for (int j = 1; j <= 6; j++) {
      if (cur % j == 0) {
        (ans += self(self, cur / j, i + 1)) %= MOD;
      }
    }
    return dp[i][cur] = ans;
  };
  cout << memo(memo, m, 0);
}

