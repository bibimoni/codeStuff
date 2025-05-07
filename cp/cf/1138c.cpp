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
  vector<vector<int>> a(n, vector<int>(m));
  for(int i = 0; i < n; i++) 
    for(int j = 0; j < m; j++) 
      cin >> a[i][j];
  vector<int> maxRows(n);
  vector<int> maxCols(m);
  vector<vector<pair<int, int>>> compress(n, vector<pair<int, int>>(m));
  for(int i = 0; i < n; i++) {
    //for each rows
    vector<int> row = a[i];
    sort(row.begin(), row.end());
    row.erase(unique(row.begin(), row.end()), row.end());
    for(int j = 0; j < m; j++) {
      compress[i][j].first = lower_bound(row.begin(), row.end(), a[i][j]) - row.begin() + 1;
    }
    maxRows[i] = row.size();
  }
  for(int i = 0; i < m; i++) {
    vector<int> col;
    for(int j = 0; j < n; j++)
      col.push_back(a[j][i]);
    sort(col.begin(), col.end());
    col.erase(unique(col.begin(), col.end()), col.end());
    for(int j = 0; j < n; j++) {
      compress[j][i].second = lower_bound(col.begin(), col.end(), a[j][i]) - col.begin() + 1;
    }
    maxCols[i] = col.size();
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int t1 = maxRows[i], t2 = maxCols[j];
      if(compress[i][j].first > compress[i][j].second) {
        t2 += compress[i][j].first - compress[i][j].second;
      }
      else {
        t1 += compress[i][j].second - compress[i][j].first;
      }
      cout << max(t1, t2) << " \n"[j == m -1];
    }
  }
}

