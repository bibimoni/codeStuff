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
    int a, b, xa, ya, xb, yb; cin >> a >> b >> xa >> ya >> xb >> yb;
    set<pair<int, int>> cnt1, cnt2;
    int dx[] = {-a, -b, a, b, -a, -b, a, b};
    int dy[] = {-b, -a, b, a, b, a, -b, -a};
    for(int i = 0; i < 8; i++) {
       cnt1.insert({xa + dx[i], ya + dy[i]});
       cnt2.insert({xb + dx[i], yb + dy[i]});
    }
    int ans = 0;
    dbg(cnt1, cnt2);
    for(auto [p1, p2] : cnt1) {
      for(auto [p3, p4] : cnt2) {
        if(p1 == p3 && p2 == p4) {dbg(p1, p3, p2, p4); ans++;}
      }
    }
    cout << ans << '\n';
  }
}


