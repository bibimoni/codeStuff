/**
 * Author: distiled
 */
#include<bits/stdc++.h>
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
  vector<int> x(1000);
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    int l, p;
    cin >> l >> p;
    
    if (c == '|') {
      x[p] += l;
      cout << "S";
    } else {
      bool ok = true;
      for (int j = p; j < p + l; j++) {
        ok &= x[p] == x[j];
      }
      if (!ok) {
        cout << "U";
        continue;
      }
      for (int j = p; j < p + l; j++) {
        x[j] += 1;
      }
      cout << 'S';
    }
  }
  cout << '\n';
}
