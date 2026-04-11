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
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m && n > 0; i++) {
    n--;
    cout << "OK\n";
  }
  for (int i = 0; i < n; i++) {
    cout << "Too Many Requests\n";
  }
}
