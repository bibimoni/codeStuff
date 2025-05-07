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
  int h, w, q;
  cin >> h >> w >> q;
  vector<vector<int>> a(h + 1, vector<int>(w + 1, 1));
  vector<array<vector<int>, 2>> jmp_x(w + 1);
  vector<array<vector<int>, 2>> jmp_y(h + 1);
  for (int i = 1; i <= w; i++) {
    for (int k = 0; k < 2; k++) {
      jmp_x[i][k] = vector<int>(h + 2);
      iota(jmp_x[i][k].begin(), jmp_x[i][k].end(), 0);
    }
  }
  for (int i = 1; i <= h; i++) {
    for (int k = 0; k < 2; k++) {
      jmp_y[i][k] = vector<int>(w + 2);
      iota(jmp_y[i][k].begin(), jmp_y[i][k].end(), 0);
    }
  }
  auto rem = [&] (int t, int cur, vector<array<vector<int>, 2>> &jump) -> void {
    jump[t][0][cur] = jump[t][0][cur - 1];
    jump[t][0][jump[t][1][cur] - 1] = jump[t][0][cur - 1];
    jump[t][1][cur] = jump[t][1][cur + 1];
    jump[t][1][jump[t][0][cur] + 1] = jump[t][1][cur + 1];    
  };

  auto ok_x = [&] (int x) -> bool {
    return 1 <= x && x <= h;
  };

  auto ok_y = [&] (int y) -> bool {
    return 1 <= y && y <= w;
  };

  while (q--) {
    int x, y;
    cin >> x >> y;
    dbg(jmp_x[2][0][4]);
    dbg(jmp_x[2][0][3]);
    dbg(x, y);
    if (a[x][y] == 1) {
      a[x][y] = 0;
      rem(y, x, jmp_x);
      rem(x, y, jmp_y);
      continue;
    }
    dbg(jmp_x[y][0]);
    // up
    {
      int pos = jmp_x[y][0][x];
      if (ok_x(pos)) {
        a[pos][y] = 0;
        rem(y, pos, jmp_x);
        rem(pos, y, jmp_y);
      }

      // if (y == 2) {
      dbg(pos, y);
      // }
    }
    // down 
    {
      int pos = jmp_x[y][1][x];
      if (ok_x(pos)) {
        a[pos][y] = 0;
        rem(y, pos, jmp_x);
        rem(pos, y, jmp_y);
      }
      // if (y == 2) {
      dbg(pos, y);
      // }
    }
    // left 
    {
      int pos = jmp_y[x][0][y];
      if (ok_y(pos)) {
        a[x][pos] = 0;
        rem(x, pos, jmp_y);
        rem(pos, x, jmp_x);
      }
      dbg(x, pos);
    }
    // right 
    {
      int pos = jmp_y[x][1][y];
      if (ok_y(pos)) {
        a[x][pos] = 0;
        rem(x, pos, jmp_y);
        rem(pos, x, jmp_x);
      }
      dbg(x, pos);
    }
    dbg("After", jmp_x[y][0]);
    dbg(a);
  }
  int ans = 0;
  for (int i = 1; i <= h; i++) {
    ans += accumulate(a[i].begin() + 1, a[i].end(), int(0));
  }
  cout << ans << '\n';
}


