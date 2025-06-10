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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int x = 0;
  for (int val = 0; val <= n; val++) {
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      cnt += a[i] >= val;
    }
    if (cnt >= val) {
      x = val;
    }
  }
  cout << x;
}
