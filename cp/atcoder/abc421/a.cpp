/**
 * Author: distiled
 */
#include "math.h"
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
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x;
  cin >> x;
  x -= 1;
  string t;
  cin >> t;
  cout << (a[x] == t ? "Yes\n" : "No\n");
}
