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
    int ans = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << "YES\n1\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      bool ok = true;
      if (ans != -1) {
        break;
      }
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        if (abs(a[i] - a[j]) % k == 0) {
          ok = false;
        } else {
          ans = i;
        }
      }
      if (!ok) {
        ans = -1;
      }
    }
    if (ans == -1) {
      cout << "NO\n";
    } else {
      cout << "YES\n" << ans + 1 << '\n';
    }
  }
}


