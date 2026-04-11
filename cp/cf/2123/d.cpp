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
    string s;
    cin >> s;

    int cnt1 = count(s.begin(), s.end(), '1');
    if (k >= cnt1) {
      cout << "Alice\n";

    } else {
      int lo = 0, hi = n - 1;
      while (lo < hi) {
      }
    }
  }
}
