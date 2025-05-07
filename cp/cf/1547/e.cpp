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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
      cin >> a[i];
    }
    vector<int> t(k);
    for (int i = 0; i < k; i++) {
      cin >> t[i];
    }
    vector<int> l(n + 1, int(2e9)), r(n + 2, int(2e9));
    for (int i = 0; i < k; i++) {
      l[a[i]] = r[a[i]] = t[i];
    }
    for (int i = 1; i <= n; i++) {
      l[i] = min(l[i - 1] + 1, l[i]);
    }
    for (int i = n; i >= 1; i--) {
      r[i] = min(r[i + 1] + 1, r[i]);
    }
    for (int i = 1; i <= n; i++) {
      cout << min(r[i], l[i]) << " \n"[i == n];
    }
  }
}

