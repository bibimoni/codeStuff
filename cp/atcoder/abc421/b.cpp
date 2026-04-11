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
  int x, y;
  cin >> x >> y;
  vector<int> a(11);
  a[1] = x;
  a[2] = y;
  for (int i = 3; i <= 10; i++) {
    int v = a[i - 1] + a[i - 2];
    string t = to_string(v);
    reverse(t.begin(), t.end());
    for (int j = 0; j < (int)t.size(); j++) {
      a[i] = a[i] * 10 + (t[j] - '0');
    }
  }

  cout << a[10];
}
