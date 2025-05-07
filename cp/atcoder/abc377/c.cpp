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
  const vector<int> dx{2, 1, -1, -2, -2, -1, 1, 2};
  const vector<int> dy{1, 2, 2, 1, -1, -2, -2, -1};
  const int ST = dx.size();
  int n, m;
  cin >> n >> m;
  int ans = n * n;
  set<pair<int, int>> st;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    st.insert({x, y});
    for (int i = 0; i < ST; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
        st.insert({nx, ny});
      }
    }
  }
  cout << ans - st.size();

}


