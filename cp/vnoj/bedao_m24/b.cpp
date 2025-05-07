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
    int xs, ys, xe, ye;
    cin >> xs >> ys >> xe >> ye;
    string s;
    cin >> s;
    int x = xs, y = ys;
    auto modify = [&] (int &x, int &y, char c, int rev) -> void {
      if(c == 'L') x = x - 1 * rev;
      if(c == 'R') x = x + 1 * rev;
      if(c == 'U') y = y - 1 * rev;
      if(c == 'D') y = y + 1 * rev; 
    };
    for(char c : s) {
      modify(x, y, c, 1);
    }
    auto manhattan = [&] (int x, int y) -> int {
      return abs(x - xe) + abs(y - ye);
    };
    bool ok = false;
    for(int i = 0; i < n; i++) {
      modify(x, y, s[i], -1);
      if(i >= k) {
        modify(x, y, s[i - k], 1);
      }
      if(i >= k - 1 && manhattan(x, y) <= k) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
