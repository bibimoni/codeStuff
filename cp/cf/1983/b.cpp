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
    for (int i = 0; i < n; i++) {
      string t;
      cin >> t;
      for (int j = 0; j < m; j++) {
        a[i][j] = t[j] - '0';
      }
    }
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      string t;
      cin >> t;
      for (int j = 0; j < m; j++) {
        b[i][j] = t[j] - '0';
      }
    }
    auto need = [&] (int x, int y) -> int {
      return ((x + 1) % 3 == y ? 1 : 2);
    };
    auto modify = [&] (int i, int j, int del) -> void {
      // dbg(a[i][j], del);
      a[i][j] += del;
      a[i][j] %= 3;
    };
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m - 1; j++) {
        if (a[i][j] == b[i][j]) {
          continue;
        }
        int d = need(a[i][j], b[i][j]);
        modify(i, j, d);
        modify(i + 1, j + 1, d);
        modify(i + 1, j, 3 - d);
        modify(i, j + 1, 3 - d);
      }
    }
    // dbg(a, b)
    cout << (a == b ? "YES\n" : "NO\n");
  }
}


