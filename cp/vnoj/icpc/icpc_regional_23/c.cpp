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
    int n; cin >> n;
    cout << "YES\n";
    cout << 7 * n << '\n';
    auto drawCell = [&] (int x, int y) {
      cout << x << ' ' << y << " 3\n";
      cout << x - 1 << ' ' << y << " 2\n";
      cout << x + 1 << ' ' << y << " 2\n";
      cout << x << ' ' << y - 1 << " 2\n";
      cout << x << ' ' << y + 1 << " 2\n";
      cout << x - 1 << ' ' << y - 1 << " 2\n";
      cout << x + 1 << ' ' << y + 1 << " 2\n";
    };
    for(int i = 0, x, y; i < n; i++) {
      cin >> x >> y;
      drawCell(x, y);
    }
  }
}

