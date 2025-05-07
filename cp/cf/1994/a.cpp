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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> idx(n * m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    if (n * m == 1) {
      cout << "-1\n";
      continue;
    }
    if ((n * m) % 2 == 0) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << a[i][j] + (a[i][j] % 2 == 0 ? -1 : 1) << " ";
        }
        cout << '\n';
      }
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (a[i][j] == n * m) {
            cout << n * m - 2 << " ";
          } else if (a[i][j] == n * m - 1) {
            cout << n * m << " ";
          } else if (a[i][j] == n * m - 2) {
            cout << n * m - 1 << " ";
          } else {
            cout << a[i][j] + (a[i][j] % 2 == 0 ? -1 : 1) << " ";
          }
        }
        cout << '\n';
      }
    }
  }
}


