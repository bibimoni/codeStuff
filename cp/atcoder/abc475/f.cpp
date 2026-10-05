/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
  int h, w;
  cin >> h >> w;
  vector<string> s;
  s = vector<string>(h + 1);
  for (int i = 1; i <= h; i++) {
    cin >> s[i];
    s[i] = " " + s[i];
  }

  if (h >= w) {
    auto tmp = vector<string>(w + 1, string(h + 1, ' '));
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        tmp[j][i] = s[i][j];
      }
    }
    swap(tmp, s);
    swap(h, w);
  }

  vector pre(h + 1, vector(w + 1, 0));
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      pre[i][j] = pre[i - 1][j] + int(s[i][j] == '.');
    }
  }

  dbg(pre, pre[1][1] - pre[0][1]);
  dbg(s);
  int ans = 0;
  for (int i = 1; i <= h; i++) {
    for (int j = i; j <= h; j++) {
      int top = 0, bot = 0;
      vector pre2(w + 1, 0);
      dbg(i, j);
      for (int k = 1; k <= w; k++) {
        if (s[i][k] == '.') {
          top = k;
        }
        if (s[j][k] == '.') {
          bot = k;
        }
        pre2[k] = pre2[k - 1] + int(pre[j][k] - pre[i - 1][k] > 0); 
        if (top != 0 && bot != 0 && pre[j][k] - pre[i - 1][k] > 0) {
          dbg(k,top, bot, pre2[min(top, bot)]);
          ans += pre2[min(top, bot)];
        }
      }
      dbg(pre2);
    }
  }

  cout << ans + 1 << '\n';
}
