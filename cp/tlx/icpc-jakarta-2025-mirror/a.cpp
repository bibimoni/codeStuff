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
  bool odd = false, even = false;
  int g = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (g == -1) {
      g = a[i];
    }
    odd |= a[i] % 2 == 1;
    even |= a[i] % 2 == 0;
    g = gcd(a[i], g);
  }

  if (g > 1) {
    cout << "1\n" << g << " 1\n";
  } else {
    cout << "2\n";
    cout << "4 2\n";
    cout << "2 1\n";
  }
}
