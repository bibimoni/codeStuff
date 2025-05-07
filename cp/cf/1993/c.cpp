// time-limit: 3000
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans = a[0];
    vector<int> co(n, 0);
    for (int i = 1; i < n; i++) {
      int c = (a[0] - a[i]) / k;
      co[i] = c - (c % 2 != 0);
      ans = max(ans, a[i] + co[i] * k);
    }
    for (int i = 1; i < n; i++) {
      if (a[i] + (co[i] + 1) * k <= ans) {
        co[i] += 2;
      }
      ans = max(ans, a[i] + co[i] * k);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int need = (ans - a[i]) / k;
      if (need % 2 != 0) {
        ok = false;
      }
    }
    cout << (ok ? ans : -1) << '\n';
  }
}


