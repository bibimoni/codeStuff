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
  int n;
  cin >> n;
  vector<int> a(n);
  bool ok = false;
  for (int &x : a) {
    cin >> x;
  }
  int v;
  cin >> v;
  for (int x : a) {
    ok |= x == v;
  }
  cout << (!ok ? "No\n" : "Yes\n");
}
