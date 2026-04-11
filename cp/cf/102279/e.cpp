  /**
   * Author: distiled
   */
  #include <bits/stdc++.h>
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }

    const int inf = 1e18;
    vector<int> dp(n + 1, inf);
    dp[1] = 0;
    int cur = 1;
    dp[2] = dp[1] + b[1]*a[2];
    for (int i = 3; i <= n; i++) {
      int tmp1 = dp[i - 1] + b[i - 1]*a[i];
      // int tmp2 = dp[cur] + b[cur]*a[i];
      int v = inf, id;
      for(int j = cur; j <= min(i, cur + 5000); ++j) {
        if(v > dp[j] + b[j]*a[i]) {
          id = j;
          v = dp[j] + b[j]*a[i];
        }
      }
      if(tmp1 >= v) {
        dp[i] = v;
        cur = id;
      }
      else {
        dp[i] = tmp1;
        cur = i - 1;
      }
    }

    cout << dp[n];
  }
