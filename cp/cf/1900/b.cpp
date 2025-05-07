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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b, c; cin >> a >> b >> c;
    a = a & 1;
    b = b & 1;
    c = c & 1;
    cout << (b == c) << ' ' << (a == c) << ' ' << (b == a) << '\n';
  }
}


