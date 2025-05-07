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
    string tmp;
    getline(cin, tmp);
    vector<vector<char>> a(8, vector<char>(8));
    for(int i = 0; i < 8; i++) 
      for(int j = 0; j < 8; j++) 
        cin >> a[i][j];
    pair<int, int> ans;
    for(int i = 0; i < 8; i++) 
      for(int j = 0; j < 8; j++) {
        if(i > 0 && j > 0 && i < 7 && j < 7  && a[i][j] == '#') {
          if(a[i - 1][j - 1] == '#' && a[i - 1][j + 1] == '#' && a[i + 1][j - 1] == '#' && a[i + 1][j + 1] == '#') {
            ans = {i + 1, j + 1};
          }
        }
      }
    cout << ans.first << ' ' << ans.second << '\n';
  }
}


