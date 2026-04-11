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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, c;
    cin >> n >> c;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }

    vector<vector<int>> pwall(n, vector<int>(n));
    for (int j = 0; j < n; j++) {
      for (int i = n - 1; i >= 0; i--) {
        pwall[i][j] = (i < n - 1 ? pwall[i + 1][j] : 0) + int(s[i][j] == '#');
      }
    }
    dbg(pwall);

    vector<int> wallsbreak(n, 0);
    vector<int> can(n, 0);
    can[c - 1] = 1;
    for (int i = n - 1; i > 0; i--) {
      vector<int> ncan(n, 0);
      vector<int> nwallsbreak(n, 0);
      dbg(wallsbreak, i);
      for (int j = 0; j < n; j++) {
        if (!can[j]) {
          continue;
        }

        for (int nxtj : vector<int>{j - 1, j, j + 1}) {
          if (nxtj < 0 || nxtj >= n) {
            continue;
          }

          if (s[i - 1][nxtj] == '.') {
            ncan[nxtj] = 1;
            // dbg(i, nxtj, s[i - 1][nxtj])
          } else {
            if (pwall[i][nxtj] == wallsbreak[nxtj]) {
              // dbg(i, nxtj, pwall[i][nxtj], wallsbreak[nxtj]);
              nwallsbreak[nxtj] = max(nwallsbreak[nxtj], wallsbreak[nxtj] + 1);
              ncan[nxtj] = 1;
            }
          }
        }
      }
      for (int j = 0; j < n; j++) {
        nwallsbreak[j] = max(nwallsbreak[j], wallsbreak[j]);
      }
      dbg(ncan, i);

      swap(can, ncan);
      swap(wallsbreak, nwallsbreak);
    }
    dbg(wallsbreak);

    for (int i = 0; i < n; i++) {
      cout << can[i];
    }
    cout << '\n';
  }
}
