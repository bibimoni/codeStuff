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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[0];
    return 0;
  }

  sort(a.begin(), a.end());
  vector<int> l;
  int l1 = a[n - 1];
  bool ok = true;
  for (int i = n - 2, j = 0; i >= 0 && i >= j; i--) {
    if (a[i] == l1) {
      continue;
    }
    if (i > j && a[i] + a[j] == l1) {
      j += 1;
      continue;
    }
    ok = false;
  }

  if (ok) {
    cout << l1;
  }

  int l2 = a[0] + a[n - 1];
  ok = false;
  if (n % 2 == 0) {
    ok = true;
    for (int i = 0; i * 2 < n; i++) {
      ok &= a[i] + a[n - i - 1] == l2;
    }
  }

  if (l1 != l2 && ok) {
    cout << ' ' << l2;
  }
}
