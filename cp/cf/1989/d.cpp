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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int mx = *max_element(a.begin(), a.end());
  const int INF = 1e9;
  vector<int> f(mx + 1, INF);
  for (int i = 0; i < n; i++) {
    f[a[i]] = min(f[a[i]], a[i] - b[i]);
  }  
  for (int i = 1; i <= mx; i++) {
    f[i] = min(f[i], f[i - 1]);
  }
  vector<int> dp(mx + 1);
  for (int i = 1; i <= mx; i++) {
    if (i - f[i] >= 0) {
      dp[i] = dp[i - f[i]] + 1;
    }
  }
  vector<int> c(m);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    cin >> c[i];
    if (c[i] > mx) {
      int tmp = (c[i] - mx - 1) / f[mx] + 1;
      ans += tmp;
      c[i] -= tmp * f[mx];
    }
    ans += dp[c[i]];
  }
  cout << ans * 2;
}


