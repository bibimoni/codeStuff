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
  int r, c, n, p;
  cin >> r >> c >> n >> p;
  vector a(r, vector(c, 0));
  vector<vector<int>> arr;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      if (a[i][j] != 0) {
        arr.push_back({a[i][j], i, j});
      }
    }
  }
  sort(arr.begin(), arr.end());
  vector<int> dir{-1, 0, 1, 0, -1};
  set<int> st;
  int step = 0;
  int add = (p > 1) + (p < n);
  while (p--) {
    auto s  = arr[p];
    for (int k = 0; k < 4; k++) {
      int x = s[1] + dir[k];
      int y = s[2] + dir[k + 1];
      if (x >= 0 && y >= 0 && x < r && y < c 
        && a[x][y] != 0 
        && a[x][y] != p && a[x][y] != p + 2 
        && a[x][y] + step <= n 
      ) {
        st.insert(a[x][y] + step);
      }
    }
    step += 1;
  }
  cout << st.size() + add << "/" << n - 1;
}

