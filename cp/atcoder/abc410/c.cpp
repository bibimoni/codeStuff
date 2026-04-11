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
  int n, q;
  cin >> n >> q;
  int off = 0;
  vector<int> val(n);
  iota(val.begin(), val.end(), 1);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, x;
      cin >> p >> x;
      p -= 1;
      val[(p - off + int(1e9) * n) % n] = x;
    } else if (type == 2) {
      int p;
      cin >> p;
      p -= 1;
      cout << val[(p - off + int(1e9) * n) % n] << '\n';
    } else if (type == 3) {
      int k;
      cin >> k;
      off -= k;
      (off += int(1e9) * n) %= n;
    }
  }
}
