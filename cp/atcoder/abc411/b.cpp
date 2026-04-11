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
  vector<int> d(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> d[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int s = 0;
    for (int j = i; j < n - 1; j++) {
      s += d[j];
      cout << s << " \n"[j == n - 2];
    }
  }
}
