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
  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  int st = -1, ed = -1;
  for (int i = 0; i < n; i++) {
    if (st == -1 && l[i] == 1) {
      st = i;
    }
    if (st != -1 && l[i] == 1) {
      ed = i;
    }
  }

  cout << ed - st;
}
