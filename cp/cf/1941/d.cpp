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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, x;
    cin >> n >> m >> x;
    char c[m];
    int r[m];
    vector<vector<int>> state(n + 1, vector<int>(m + 1, 0));
    state[x][0] = 1;
    auto go = [&] (int pos, int dis, int clockwise) {
      if(clockwise) {
        return ((pos - 1 + dis) % n) + 1;
      }      
      else {
        return ((pos - 1 - dis + n) % n) + 1;
      }
    };
    for(int i = 0; i < m; i++) {
      cin >> r[i] >> c[i];
      for(int j = 1; j <= n; j++) {
        if(state[j][i] == 1) {
          if(c[i] == '0' || c[i] == '?')
            state[go(j, r[i], true)][i + 1] = 1;
          if(c[i] == '1' || c[i] == '?')
            state[go(j, r[i], false)][i + 1] = 1;
        }
      } 
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
      if(state[i][m] == 1) {
        ans.push_back(i);
      }
    }
    cout << ans.size() << '\n';
    for(int i : ans) {
      cout << i << ' '; 
    }
    cout << '\n';
  }
}


