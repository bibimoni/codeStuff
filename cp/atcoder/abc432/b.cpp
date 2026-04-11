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
  int x;
  cin >> x;
  vector<int> d;
  while (x) {
    d.push_back(x % 10);
    x /= 10;
  }
  sort(d.begin(), d.end());
  for (int i = 0; i < int(d.size()); i++) {
    if (d[i] != 0) {
      swap(d[i], d[0]);
      break;
    }
  }

  for (int i : d) {
    cout << i;
  }
}
