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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    int cnt = 0;
    for(string &i : a) {
      cin >> i;
      int curr = 0;
      for(char c : i) {
        curr += c == '#';
      }
      cnt = max(curr, cnt);
    }
    pair<int, int> ans;
    for(int i = 0; i < n; i++) {
      int curr = 0;
      for(int j = 0; j < m; j++) {
        curr += a[i][j] == '#';
      }
      if(curr == cnt) {
        curr = 0;
        for(int j = 0; j < m; j++) {
          curr += a[i][j] == '#';
          if(curr == (int) ceil(cnt / 2.0) ) {
            ans = {i + 1, j + 1};
            break;
          }
        }
      }
    }
    cout << ans.first << ' ' << ans.second << '\n';
  }
}


