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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, w, h;
    cin >> n >> k >> w >> h;
    string s;
    cin >> s;
    map<pair<int, int>, int> mp;
    int x = 0, y = 0;
    for (char c : s) {
      if (c == 'U') {
        y += 1;
      } else if (c == 'D') {
        y -= 1;
      } else if (c == 'L') {
        x -= 1;
      } else if (c == 'R') {
        x += 1;
      }
      x = (x + 2 * w) % (2 * w);
      y = (y + 2 * h) % (2 * h);
      mp[{x, y}] += 1;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
      int nx = ((-i * x + 2 * w) % (2 * w) + (2 * w)) % (2 * w);
      int ny = ((-i * y + 2 * h) % (2 * h) + (2 * h)) % (2 * h);
      ans += mp[{nx, ny}];
    }
    cout << ans << '\n';
  }
}

