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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int &x : p) {
      cin >> x;
    }
    vector<int> d(n);
    for (int &x : d) {
      cin >> x;
    }

    auto findNextTurn = [&](int pos, int time, int dir) -> int {
      if (!dir) {
        for (int i = n - 1; i >= 0; i--) {
          if (p[i] > pos) {
            continue;
          }
          if (d[i] == (time + pos - p[i] + int(1e9) * k) % k) {
            return i;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (p[i] < pos) {
            continue;
          }
          if (d[i] == (time + p[i] - pos + int(1e9) * k) % k) {
            return i;
          }
        }
      }
      return -1;
    };

    int q;
    cin >> q;
    while (q--) {
      int x;
      cin >> x;
      vector<vector<int>> wasp(n, vector<int>(k, 0));
      vector<vector<int>> wasn(n, vector<int>(k, 0));
      int dir = 1;
      int curTime = 0;
      int pos = x;
      bool out = true;
      while (true) {
        int nxt = findNextTurn(pos, curTime, dir);
        if (nxt == -1) {
          break;
        }
        if (dir == 1) {
          if (wasp[nxt][d[nxt]]) {
            out = false;
            break;
          }
          wasp[nxt][d[nxt]] = 1;
        } else {
          if (wasn[nxt][d[nxt]]) {
            out = false;
            break;
          }
          wasn[nxt][d[nxt]] = 1;
        }
        dir ^= 1;
        pos = p[nxt] + (dir ? 1 : -1);
        curTime = d[nxt] + 1;
      }
      cout << (out ? "YES\n" : "NO\n");
    }
  }
}
