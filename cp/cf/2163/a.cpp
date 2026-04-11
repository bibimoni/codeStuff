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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int can = true;
    sort(a.begin(), a.end());
    for (int i = 1; i + 1 < n; i += 2) {
      can &= a[i] == a[i + 1];
    }
    cout << (!can ? "NO\n" : "YES\n");
  }
}
