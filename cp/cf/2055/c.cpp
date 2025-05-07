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
    string s;
    cin >> s;
    vector a(n, vector(m, int(0)));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }

    vector<int> s_rows(n), s_cols(m);
    for (int i = 0; i < n; i++) {
      s_rows[i] = accumulate(a[i].begin(), a[i].end(), int(0));
    }
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        s_cols[j] += a[i][j];
      }
    }

    vector<int> rows(n), cols(m);
    vector<pair<int, int>> path;
    pair cur{0, 0};
    path.push_back(cur);
    rows[0] += 1;
    cols[0] += 1;
    for (char c : s) {
      if (c == 'D') {
        cur.first += 1;
      } else {
        cur.second += 1;
      }
      rows[cur.first] += 1;
      cols[cur.second] += 1;
      path.push_back(cur);
    }
    assert(cur.first == n - 1 && cur.second == m - 1);
    
    for (int i = 0; i < (int)path.size(); i++) {
      auto [x, y] = path[i];
      int val = 0;
      if (rows[x] == 1) {
        val = -s_rows[x];
      } else {
        val = -s_cols[y];
      }
      cols[y] -= 1;
      rows[x] -= 1;
      s_rows[x] += val;
      s_cols[y] += val;
      a[x][y] = val;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << " \n"[j == m - 1];
      }
    }
  }
} 


