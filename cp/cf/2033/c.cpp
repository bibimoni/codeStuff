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
    for (int i = 1; i < n - i; i++) {
      if (a[i] == a[i - 1] || a[n - i - 1] == a[n - i]) {
        swap(a[i], a[n - i - 1]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += a[i] == a[i + 1];
    }
    cout << ans << '\n';
  }
}


