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
    int n, k;
    cin >> n >> k;
    int curr = 1;
    vector<int> ans(n, 0);
    int cnt = 0;
    int pos = 0;
    bool up = true;
    while(cnt < n) {
      // dbg(ans, pos);
      if(up) {
        for(int i = pos; i < n; i += k) {
          ans[i] = curr++;
          cnt++;
        }
      }
      else {
        vector<int> ps;
        for(int i = pos; i < n; i += k) {
          ps.push_back(i);
        }
        reverse(ps.begin(), ps.end());
        for(int i : ps) {
          ans[i] = curr++;
          cnt++;
        }
      }
      dbg(ans, up);
      pos++;
      up = !up;
    }
    for(int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}


