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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    auto can = [&] (int x) -> bool {
      for(int i = 0; i <= n; i++)
        dp[i].assign(m + 1, 0);
      dp[1][1] = 1;
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
          if(i == 1 && j == 1)
            continue;
          if(a[i][j] % x != 0)
            continue;
          if(i > 1)
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
          if(j > 1)
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
      }
      return (bool) dp[n][m];
    };
    int maxE = __gcd(a[1][1], a[n][m]);
    int ans = 1;
    vector<int> divs;
    for(int i = 1; i * i <= maxE; i++) {
      if(maxE % i == 0) {
        divs.push_back(i);
        if(maxE != i * i)
          divs.push_back(maxE / i);
      }
    }
    sort(divs.begin(), divs.end(), greater<int>());
    for(int div : divs) {
      if(can(div)) {
        ans = max(ans, div);
        break;
      }
    }
    cout << ans << '\n';
  }
}

