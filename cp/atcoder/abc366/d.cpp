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
  int n;
  cin >> n;
  vector<vector<vector<int>>> a(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
  vector<vector<vector<int>>> s(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        cin >> a[i][j][k];
        s[i][j][k] = 
          s[i - 1][j][k] + s[i][j - 1][k] + s[i][j][k - 1] 
          - s[i - 1][j - 1][k] - s[i - 1][j][k - 1] - s[i][j - 1][k - 1] 
          + s[i - 1][j - 1][k - 1] 
          + a[i][j][k];
      }
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int lx, rx, ly, ry, lz, rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;
    cout << s[rx][ry][rz] 
      - s[lx - 1][ry][rz] - s[rx][ly - 1][rz] - s[rx][ry][lz - 1]
      + s[lx - 1][ly - 1][rz] + s[lx - 1][ry][lz - 1] + s[rx][ly - 1][lz - 1]
      - s[lx - 1][ly - 1][lz - 1] << '\n';
  }
}


