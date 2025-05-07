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
  int n, R, r;
  cin >> n >> R >> r;
  if(r > R || (n > 1 && r * 2 > R)) {
    cout << "NO\n";
    return 0;
  }
  if(r * 2 > R && n == 1) {
    cout << "YES\n";
    return 0;
  }
  int angle = abs(180 * asin(r / (double) (R - r))) / 3.14159265359;
  cout << (n <= (int)(360.0 / (int) (2 * angle)) ? "YES\n" : "NO\n");
}

