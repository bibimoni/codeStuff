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
    int n;
    cin >> n;
    string s; cin >> s;
    string ma = "map", pi = "pie";
    int ans = 0;
    for(int i = 2; i < n; i++) {
      string cmp = s.substr(i - 2, 3);
      // dbg(cmp);
      if(cmp == "map" && i + 2 < n && s.substr(i, 3) == "pie") {
        ans++;
        i += 2;
      }
      else {
        if(cmp == "map" || cmp == "pie") {
          ans++;
          i += 2;
        }
      }
    }
    cout << ans << '\n';
  }
}


