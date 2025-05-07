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
    string s; 
    cin >> s;
    int n = s.size();
    s = " " + s;
    auto good = [&] (int x, int y) -> bool {
      if(s[x] == '?' || s[y] == '?')
        return true;
      return s[x] == s[y];
    };
    int ans = 0;
    for(int len = (n / 2) * 2; len >= 2; len -= 2) {
      if(ans)
        break;
      set<int> idx;
      for(int i = (len / 2) + 1; i <= len; i++) {
        if(!good(i - (len / 2), i))
          idx.insert(i);
      }
      if(!idx.size()) {
        ans = len;
        break;
      }
      for(int i = len + 1; i <= n; i++) {
        if(idx.find(i - (len / 2)) != idx.end()) 
          idx.erase(i - (len / 2));
        if(!good(i - (len / 2), i))
          idx.insert(i);
        if(!idx.size()) {
          ans = len;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}


