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
#define int              long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q; cin >> n >> q;
  deque<array<int, 2>> dq(n);
  for(int i = 0; i < n; i++) {
    dq[i] = {i + 1, 0};
  } 
  while(q--) {
    int type; cin >> type;
    if(type == 1) {
      char c; cin >> c;
      auto [x, y] = dq.front();
      dq.pop_back();
      if(c == 'U') y++;
      else if(c == 'D') y--;
      else if(c == 'R') x++;
      else x--;
      dq.push_front({x, y});
    }
    if(type == 2) {
      int p; cin >> p; p--;
      cout << dq[p][0] << ' ' << dq[p][1] << '\n';
    }
  }
}


