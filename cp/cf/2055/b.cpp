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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int cnt = 0, idx = -1, diff = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i]) {
        cnt += 1;
        idx = i;
        diff += b[i] - a[i];
      }
    }
    if (cnt > 1) {
      cout << "NO\n";
    } else {
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (i != idx) {
          ok &= a[i] - diff >= b[i];
        }
      }
      cout << (ok ? "YES\n" : "NO\n");
    }
  }
}


