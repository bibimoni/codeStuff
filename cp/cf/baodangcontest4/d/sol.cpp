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
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++)  
      for(int j = 1; j <= m; j++)
        cin >> a[i][j];
    int q;
    cin >> q;
    vector<vector<int>> pre(n + 2, vector<int>(m + 2, 0));
    while(q--) {
      int a, b, c, d, k;
      cin >> a >> b >> c >> d >> k;
      pre[a][b] += k;
      pre[c + 1][b] -= k;
      pre[a][d + 1] -= k;
      pre[c + 1][d + 1] += k;
    }

    for(int i = 1; i <= n; i++) 
      for(int j = 1; j <= m; j++) 
        pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
      
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        cout << a[i][j] + pre[i][j] << " \n"[j == m];
  }
}

