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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    vector<string> b(n + 1);
    int diff = 0;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      b[i] = " " + b[i];
      for (int j = 1; j <= m; j++) {
        diff += (b[i][j] == '1' ? 1 : -1) * a[i][j];
      }
    }
    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (b[i][j] == '1' ? 1 : -1);
      }
    }
    int g = 0;
    for (int i = k; i <= n; i++) {
      for (int j = k; j <= m; j++) {
        int t = pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k];
        // dbg(t);
        g = gcd(g, abs(t));
      }
    }
    if (diff == 0 || (g > 0 && diff % g == 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}


