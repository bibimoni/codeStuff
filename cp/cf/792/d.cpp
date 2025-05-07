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

// 435255549744527627
// 288230378299195391

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  if(n == 1) {
    while (q--) {
      int u;
      string s;
      cin >> u >> s;
      cout << "1\n";
    }
    return 0;
  }
  int h_max = __builtin_ctzll(n + 1);
  int root = (n + 1) / 2;
  auto findH = [&] (int u) -> int {
    if (u <= 0 || u > n) {
      return -1;
    }
    int h_cur = h_max;
    int diff_cur = int(1) << (h_max - 2);
    int cur = root;
    while (cur != u) {
      if (cur < u) {
        cur += diff_cur;
      } else {
        cur -= diff_cur;
      }
      diff_cur /= 2;
      h_cur -= 1;
    }
    return h_cur;
  };
  while (q--) {
    int u;
    string s;
    cin >> u >> s;
    int h_cur = findH(u);
    int cur = u;
    for (char c : s) {
      if (c != 'U') {
        if (cur % 2) {
          continue;
        }
        int nxt_diff = int(1) << (h_cur - 2);
        h_cur -= 1;
        if (c == 'L') {
          cur -= nxt_diff;
        } else if (c == 'R') {
          cur += nxt_diff;
        }
      } else{
        if (cur == root) {
          continue;
        }
        int nxt_diff = int(1) << (h_cur - 1);
        h_cur += 1;
        int nxt1 = cur + nxt_diff;
        int nxt2 = cur - nxt_diff;
        if (nxt1 <= n && findH(nxt1) == h_cur) {
          cur = nxt1;
        } 
        if (nxt2 > 0 && findH(nxt2) == h_cur) {
          cur = nxt2;
        }
      }
    }
    cout << cur << '\n';
  }
}

