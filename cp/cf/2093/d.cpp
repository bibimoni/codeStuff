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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  const int N = 2;
  
  vector val(N + 1, vector(N + 1, int(0)));
  val[1][1] = 1;
  val[1][2] = 4;
  val[2][1] = 3;
  val[2][2] = 2;
  map<int, pair<int, int>> mp;
  mp[1] = {1, 1};
  mp[2] = {2, 2};
  mp[3] = {2, 1};
  mp[4] = {1, 2};

  while (tt--) {  
    int n, q;
    cin >> n >> q;
    while (q--) {      
      string s;
      cin >> s;
      if (s == "->") {
        int x, y;
        cin >> x >> y;
        int tot = int(1) << (2 * n);
        int add = 0;
        int b = int(1) << n;
        while (tot > 4) {
          if (x * 2 <= b && y * 2 <= b) {
            // tl
          } else if (x * 2 > b && y * 2 > b) {
            // br
            x -= (b >> 1);
            y -= (b >> 1);
            add += tot >> 2;
          } else if (x * 2 > b && y * 2 <= b) {
            // bl
            x -= (b >> 1);
            add += tot >> 1;
          } else {
            y -= (b >> 1);
            add += (tot >> 2) * 3;
          }
          tot >>= 2;
          b >>= 1;
        }
        cout << val[x][y] + add << '\n';
      } else if (s == "<-") {
        int d;
         cin >> d;
        int tot = int(1) << (2 * n);
        int x_add = 0;
        int y_add = 0;
        int b = int(1) << n;
        while (tot > 4) {
          int fourth = tot >> 2;
          if (d <= fourth) {
            // tl
          } else if (d <= fourth * 2) {
            // br
            d -= fourth;
            x_add += b >> 1;
            y_add += b >> 1;
          } else if (d <= fourth * 3) {
            // bl
            d -= fourth * 2;
            x_add += b >> 1;
          } else {
            d -= fourth * 3;
            y_add += b >> 1;            
          }
          tot >>= 2;
          b >>= 1;
        }
        auto coord = mp[d];
        cout << coord.first + x_add << ' ' << coord.second + y_add << '\n';
      }
    }
  }
}


