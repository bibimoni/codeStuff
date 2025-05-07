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
    int s_0 = 0, s_1 = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i & 1) {
        s_0 += a[i];
      } else {
        s_1 += a[i];
      }
    }
    int c_0 = n / 2, c_1 = n - c_0;
    if (s_0 % c_0 != 0 || s_1 % c_1 != 0) {
      cout << "NO\n";
    } else {
      cout << (s_0 / c_0 != s_1 / c_1 ? "NO\n" : "YES\n");
    }
  }
}


