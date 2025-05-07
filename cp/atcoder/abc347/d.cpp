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
  int a, b, c;
  cin >> a >> b >> c;
  int x = 0, y = 0;
  bool isSwap = false;
  if(a < b) {
    isSwap = true;
    swap(a, b);
  }
  int diff = a - b;
  vector<int> occ(61, 0);
  for(int i = 0; i <= 60 && diff > 0; i++) {
    if((c >> i) & 1) {
      occ[i] = 1;
      x |= (1ll << i);
      diff--;
    }
  }
  if(diff > 0) {
    cout << "-1";
    return 0;
  }
  a = b;
  bool turnX = true;
  for(int i = 0; i <= 60; i++) {
    if(occ[i])
      continue;
    if((c >> i) & 1) {
      occ[i] = 1;
      if(turnX) {
        x |= (1ll << i);
        a--;
      }
      else {
        y |= (1ll << i);
        b--;
      }
      turnX = !turnX;
    }
  }
  dbg(a, b, x, y);
  if(a < 0 || b < 0 || a != b) {
    cout << "-1";
    return 0;
  }
  dbg("HERE");
  for(int i = 0; i <= 60 && a > 0 && b > 0; i++) {
    if((c >> i) & 1)
      continue;
    x |= (1ll << i);
    y |= (1ll << i);
    a--;
    b--;
  }
  dbg(a, b, x, y);
  bool ok = (a == 0 && b == 0);
  for(int i = 60; i >= 0; i--) {
    // dbg(ok, i, (c >> i) & 1);
    ok &= !(((c >> i) & 1) == 1 && !occ[i]);
  }
  if(isSwap)
    swap(x, y);
  if(!ok) {
    cout << "-1";
  }
  else {
    cout << x << ' ' << y;
  }
}


