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
  freopen("ROBOT.INP", "r", stdin);
  freopen("ROBOT.OUT", "w", stdout);
  int x, y, xt, yt;
  cin >> x >> y >> xt >> yt;
  int m = min(abs(x - xt), abs(y - yt));
  int M = max(abs(x - xt), abs(y - yt));
  cout << m + (M - m);
}


