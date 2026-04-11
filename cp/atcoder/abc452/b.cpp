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
  int h, w;
  cin >> h >> w;
  cout << string(w, '#') << '\n';
  for (int i = 0; i + 2 < h; i++) {
    cout << '#' << string(w - 2, '.') << "#\n";
  }
  cout << string(w, '#') << '\n';
}
