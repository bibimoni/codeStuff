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
  int n;
  cin >> n;
  vector<string> s(n);
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    m = max(m, int(s[i].size()));
  }

  for (int i = 0; i < n; i++) {
    int k = m - s[i].size();
    k /= 2;
    cout << string(k, '.') + s[i] << string(k, '.') << '\n';
  }
}
