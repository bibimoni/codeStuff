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

#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  vector<bool> rows(n), cols(m);
  for(int r, c, i = 0; i < k; i++) {
    cin >> r >> c;
    rows[--r] = true, cols[--c] = true;
  }
  int cntRows = 0, cntCols = 0;
  for(int i = 0; i < n; i++) cntRows += !rows[i];
  for(int i = 0; i < m; i++) cntCols += !cols[i];
  cout << n * m - (cntRows * m + cntCols * n - cntCols * cntRows);
}

