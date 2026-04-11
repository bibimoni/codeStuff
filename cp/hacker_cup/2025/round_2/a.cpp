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
  freopen("deciding_points_input.txt", "r", stdin);
  freopen("deciding_points_output.txt", "w", stdout);
  int tt;
  cin >> tt;
  for (int ttt = 1; ttt <= tt; ttt++) {
    int n, m;
    cin >> n >> m;
    if (n < m) {
      cout << "Case #" << ttt << ": NO\n";
    } else if (m <= n && n <= 2 * m - 2) {
      cout << "Case #" << ttt << ": YES\n";
    } else {
      cout << "Case #" << ttt << ": " << (n % 2 == 0 ? "YES\n" : "NO\n");
    }
  }
}
